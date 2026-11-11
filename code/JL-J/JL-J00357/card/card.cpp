#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
int f[300005];
int b[300005];
bool bo[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        int p=0;
        if(f[a[i]]==0){
            memset(b,0,sizeof b);
            for(int j=i;j<=n;j++){
                if(bo[a[j]]==0&&a[j]!=a[i]) b[++p]=a[j];
            }
            int tnt=0;
            bool q=0;
            for(int j=i;j>=1;j--){
                if(q==0){
                    for(int k=1;k<=p;k++){
                        if(a[j]==b[k]){
                            tnt++;
                            q=1;
                            break;
                        }
                    }
                }
                else if(a[j]!=a[i]){
                    tnt++;
                }
            }
            f[a[i]]=i-tnt;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<' ';
    }
    return 0;
}
