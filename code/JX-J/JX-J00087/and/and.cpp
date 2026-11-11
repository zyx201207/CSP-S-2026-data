#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
long long len;
int a[N];
int ax[N];
int ans;
bool b;
int f(int a,int x){
    if(x%2==1)return f(a*a,x/2)*a;
    return f(a*a,x/2); 
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ax[i]=a[i];
        if(a[i]==i-1)b=1;
    }
    if(n<=100||(n<=2000&&m==2)){
        while(m--){
            for(int i=1;i<=n;i++){
                int x=0;
                for(int j=1;j<=n;j++){
                    x=max(x,ax[i]^a[j]);
                }
                ax[i]=x;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,ax[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==1||m==n||m==m-1){
        if(m==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,ax[i]);
            }
            cout<<ans;
            return 0;
        }
        else if(m==n-1){
            int t=a[1];
            for(int i=2;i<=n;i++){
                t=t^a[i];
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,t^a[i]);
            }
            cout<<ans;
            return 0;
        }
        else{
            for(int i=2;i<=n;i++){
                a[i]=a[i-1]^a[i];
            }
            cout<<a[n];
            return 0;
        }
    }
    if(b==1){
        int t=log(n);
        int ans=f(2,n+1);
        cout<<ans-1;
    }
    cout<<0;
    return 0;
}
