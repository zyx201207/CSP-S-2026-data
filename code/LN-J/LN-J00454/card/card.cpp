#include <bits/stdc++.h>
using namespace std;
long long n,m,a[999999],cnt[999999],z;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    //cout<<1<<endl;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        long long t[99999]={0},z[99999];
        long long c=1;
        for(int j=i;j<=n;++j){
            z[c]=a[j];
            c+=1;
            t[a[j]]++;
            if(t[a[j]]==2){for(int k=c-2;k>=1;--k){
                if(z[k]==a[j]){
                    break;
                }
                else{
                    t[z[k]]=0;
                }
            }
            t[a[j]]-=1;
            }
        }
        for(int j=1;j<=m;++j){
            if(t[j])cnt[j]+=1;
        }
    }
    for(int i=1;i<=m;++i)cout<<cnt[i]<<" ";
    return 0;
}
