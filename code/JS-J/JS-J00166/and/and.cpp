#include<bits/stdc++.h>
using namespace std;
const int N=pow(2,30)+100;
int n,m,ans=-1;
int a[200010]={0};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]);
        }
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
