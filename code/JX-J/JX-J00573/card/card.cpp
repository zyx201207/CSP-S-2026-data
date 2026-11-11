#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],k,s,b,c[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m<=2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1)k++;
            else s++;
        }
        if(a[n]==1){
            cout<<n<<" "<<s;
        }else{
            cout<<k<<" "<<n;
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=n;i>=1;i--){
            if(!c[a[i]]){
                c[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<c[i]<<" ";
        }
    }
    return 0;
}
