#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int l=0;
        string p;
        for(int j=i;j<=n;j++){
            l=p.size();
            for(int k=0;k<=l;k++){
                if(p[k]-'0'==a[j]&&k<l){
                    p.erase(k+1,l-1);
                    break;
                }
                else{
                    p+=a[j]+'0';
                }
            }
        }
        for(int j=1;j<=m;j++){
            int k=p.find(j+'0');
            if(k<p.size()){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
