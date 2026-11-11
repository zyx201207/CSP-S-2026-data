#include<bits/stdc++.h>
using namespace std;
long long a[500010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long zd=-1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        zd=max(zd,a[i]);
    }
    if(m==1){
        cout<<zd;
    }else if(m==2){
        zd=-1e18;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                zd=max(zd,(a[i]&a[j]));
            }
        }
        cout<<zd;
    }else{
        sort(a+1,a+n+1,cmp);
        unique(a+1,a+n+1);
        cout<<a[m];
    }
    return 0;
}