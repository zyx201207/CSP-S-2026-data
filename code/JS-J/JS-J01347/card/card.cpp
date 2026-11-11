#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool b[300005];
long long ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        memset(b,false,sizeof b);
        long long l=j;
        for(int i=j;i<=n;i++){
            if(b[a[i]]==true){
                l=i;
            }
            b[a[i]]=true;
        }
        for(int i=l;i<=n;i++){
                ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
