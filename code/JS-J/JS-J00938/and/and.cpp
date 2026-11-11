#include <bits/stdc++.h>
using namespace std;
int s[1000000][32];
bool b[1000000]
int main(){
    freopen("and.in";"r";stdin);
    freopen("and.out";"w";stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        int s1;cin >> s1;
        int j= 0;
        while(s1>0){
            s[i][++t] = s1%2;
            s1/=2;
        }
    }
    for(int i = 1,i<=n,++i){
        b[i] = 1;
    }
    for(int i = 32;i>=1;i--){
        int num = 0;
        for(int j=1;j<=n;++j){
            if(s[j][i] == 1){
                num += 1;
            }
        }
        if(num < m){
            continue;
        }
        for(int j=1;j<=n;++j){
            if(b[i]&&s[j][i] == 0){
                b[j] = 0;
            }
        }

    }
    return 0;
}
