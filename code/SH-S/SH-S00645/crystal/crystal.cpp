#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
#define int long long
int num[signed(5e5+5)];
int pre[signed(5e5+5)];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    sort(num + 1, num + 1 + n);

    int diff = num[2] - num[1];
    bool xz = true;
    bool xz1 = true;
    if(abs(num[1]) > 100 or abs(num[2])>100){
        xz1 = false;
    }

    for(int i = 3; i <= n; i++){
        if(xz == false and xz1 == false) break;
        if(num[i] - num[i - 1] != diff) xz = false;
        if(abs(num[i] > 100)) {
            xz1 = false;
        }
    }
    if(xz == true){
        int res = LLONG_MIN;
        int st = 1;
        pre[st] = 0;
        bool success = false;
        for(int i = st + 1; i <= n + 1; i++){
            //cout << "st = " << st << " i = " << i << " pre[i-1] = " << pre[i - 1] << " num[i]-num[i - 1] = " << num[i]-num[i - 1] << " pre[i] = " << pre[i - 1] + ((i - st)*(num[i]-num[i - 1])) << endl;
            pre[i] = pre[i - 1] + ((i - st)*(num[i]-num[i - 1]));
            if(pre[i] > m){
                res = max(res, i - st);
                success = true;
                break;
            }
        }
        if(success == false) res = max(res,n+1-st);
        //cout << "st = " << st << " res = " << res << endl;
        //for(int j = st + 1; j <= n; j++) cout << pre[j] << " ";
        //cout << endl;
        cout << res <<endl;
        return 0;
    }
    
    if(xz1 == true && n*n > 1e10){
        vector<int> num1;
        vector<int> numcnt;
        num1.reserve(210);
        numcnt.resize(210);
        for(int i = 1; i <= n; i++){
            num[i]+=101;
            numcnt[num[i]]++;
        }
        int kinds = 0;
        for(int i = 0; i <= 209; i++){
            if(numcnt[i] != 0) {
                kinds++;
                num1.push_back(i);
            }
        }
        int res = LLONG_MIN;
        //for(auto x: num1) cout << x << " " << numcnt[x] << endl;

        cout << endl;
        for(int st = 1; st <= n; st++){
            pre[st] = 0;
            bool success = false;

            for(int i = st + 1; i <= kinds; i++){
                //cout << "st = " << st << " i = " << i << " pre[i-1] = " << pre[i - 1] << " num1[i]-num1[i - 1] = " << num1[i]-num1[i - 1] << " numcnt[num1[i - 2]] = " << numcnt[num1[i - 2]] << " pre[i] = " << pre[i - 1] + ((i - st)*(num1[i]-num1[i - 1])*numcnt[i - 1]) << endl;
                pre[i] = pre[i - 1] + ((i - st)*(num1[i]-num1[i - 1])*numcnt[num1[i - 2]]);
                if(pre[i] > m){
                    res = max(res, i - st);
                    success = true;
                    break;
                }
            }
            //if(success == false) res = max(res,n+1-st);
            //cout << "st = " << st << " res = " << res << endl;
            //for(int j = st + 1; j <= n; j++) cout << pre[j] << " ";
            //cout << endl << endl;
        }
        cout << res << endl;
        return 0;
    }

    int res = LLONG_MIN;
    for(int st = 1; st <= n; st++){
        pre[st] = 0;
        bool success = false;
        for(int i = st + 1; i <= n + 1; i++){
            //cout << "st = " << st << " i = " << i << " pre[i-1] = " << pre[i - 1] << " num[i]-num[i - 1] = " << num[i]-num[i - 1] << " pre[i] = " << pre[i - 1] + ((i - st)*(num[i]-num[i - 1])) << endl;
            pre[i] = pre[i - 1] + ((i - st)*(num[i]-num[i - 1]));
            if(pre[i] > m){
                res = max(res, i - st);
                success = true;
                break;
            }
        }
        if(success == false) res = max(res,n+1-st);
        //cout << "st = " << st << " res = " << res << endl;
        //for(int j = st + 1; j <= n; j++) cout << pre[j] << " ";
        //cout << endl;
    }

    cout << res << endl;
    return 0;
}
