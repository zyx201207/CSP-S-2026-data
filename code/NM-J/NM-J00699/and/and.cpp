#include<bits/stdc++.h>
using namespace std;
int ans,n,m,y[2],z;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
        z=max(z,x[i]);
    }
    if(m==1){
        cout<<"0";
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j) ans=max(ans,x[i]&x[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==3){
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && k!=j && i!=k) ans=max(ans,x[i]&x[j]&x[k]);
                }
            }
        }
        if(m>3) cout<<z;
return 0;
}
