#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[500001],top,ans[500001],q[500001],qt;
bool f[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n>=500000){
        for(int i = 1;i <= m;i++) cout << 0 << ' ';
        return 0;
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(n--){
        for(int i = 1;i <= n;i++){
            for(int j = 1;i <= top;j++){
                if(a[i]==s[j]){
                    for(int k = j;k <= top;k++){
                        q[++qt]=s[k];
                    }
                    top=j;
                    break;
                }
            }
            s[i]=a[i];
        }
        for(int j = 1;j <= top;j++){
            q[++qt]=s[j];
            f[s[j]]=1;
        }
        for(int j = 2;j<=n;j++)a[j]=q[j];
        for(int j=1;j<=m;j++){
            ans[j]+=f[j];
            f[j]=0;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
