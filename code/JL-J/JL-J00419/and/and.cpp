

#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long n,m,a,ans;
long long len[N];
long long w[10005][10005],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a;
        b[i] = a;
        while(a != 0){
            len[i]++;
            w[i][len[i]] = a % 2;
            a /= 2;
        }
    }
    if(m == 1){
        sort(b + 1,b + 1 + n,greater<long long>());
        cout<<b[1];
        return 0;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            long long cum = 1,sum = 0;
            for(int kk = 1;kk <= max(len[i],len[j]);kk++){
                if(w[i][kk] == w[j][kk] && w[i][kk] == 1){
                    sum += cum;
                }
                cum *= 2;
            }
            ans = max(ans,sum);
        }
    }
    cout<<ans;
    return 0;
}

