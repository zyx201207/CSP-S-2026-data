#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+1+n,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        int maxm=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxm=max(maxm,a[i]&a[j]);
            }
        }
        cout<<maxm;
        return 0;
    }
    return 0;
}
