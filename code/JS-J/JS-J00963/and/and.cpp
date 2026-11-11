#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(i==m){
                cout<<a[i];
                break;
            }
        }
    }
    return 0;
}
