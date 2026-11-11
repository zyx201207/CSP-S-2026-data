#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long  n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long  mx1=-1;
        for(int i=1;i<=n;i++){
            mx1=max(mx1,a[i]);
        }
        cout<<mx1;
    }
    if(m==2){
        long long mx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i]&a[j]));

            }
        }
        cout<<mx;
    }
    if((m==n)&&(m!=2)){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }





    return 0;
}
