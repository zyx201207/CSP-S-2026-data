#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
int n,m,T;
int a[N],b[N];
int ans;
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    T=1;
    while(T<=m){
        for(int i=1;i<=n;i++) b[i]=a[i];
        for(int i=T;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(b[i]==b[j]) memset(b,0,j);
            }
            if(b[i]==T) ans++;
        }
        cout<<ans<<" ";
        T++;
    }
    return 0;
}