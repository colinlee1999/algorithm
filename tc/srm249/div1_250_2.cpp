#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


double dp[1<<13];


class TableSeating {

    public:
        double getExpected(int numTables, vector <int> probs) {
            for(int i=0; i<(1<<13); i++)dp[i] = 0.0;
            dp[0] = 1.0;

            double ans = 0;
            for(int cur_state=0; cur_state<(1<<numTables); cur_state++){
                for(int i=0; i<probs.size(); i++){
                    int n_people = i+1;
                    int could_place = 0;
                    int tmp = (1<<(i+1)) -1;
                    for(int j=0; j<=(numTables-(i+1)); j++){
                        if(  ((tmp<<j)&cur_state)==0 ){
                            could_place++;
                        }
                    }
                    if(could_place>0){
                        for(int j=0; j<=(numTables-(i+1)); j++){
                            if(  ((tmp<<j)&cur_state)==0 ){
                                int new_state = cur_state | (tmp<<j) ;
                                dp[new_state] += probs[i]*dp[cur_state]*1.0/(100.0*could_place);
                            }
                        }
                    }else{
                        ans += dp[cur_state]*probs[i]*1.0/(100)*__builtin_popcount(cur_state);
                        //cout<<"dp[cur_state] = "<<dp[cur_state]<<" now ans = "<<ans<<" state is "<<cur_state<<endl;
                    }
                }
            }

            return ans;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, double p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    TableSeating *obj;
    double answer;
    obj = new TableSeating();
    clock_t startTime = clock();
    answer = obj->getExpected(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    vector <int> p1;
    double p2;

    {
        // ----- test 0 -----
        p0 = 4;
        int t1[] = {100};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 4.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        p0 = 4;
        int t1[] = {0,100};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 3.3333333333333335;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        p0 = 5;
        int t1[] = {0,0,0,0,0,50,50};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 0.0;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        p0 = 12;
        int t1[] = {9,9,9,9,9,9,9,9,9,9,10};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 7.871087929710551;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
