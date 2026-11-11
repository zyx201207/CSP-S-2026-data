#include<bits/stdc++.h>
using namespace std;
int n,a[500005],mx,b[500005];
long long m,s;
bool cmp(int x,int y){
    return x<=y;
}
int c(){
    for(int i=1;i<=n-1;i++){
        s=0;
        for(int k=1;k<=n;k++)b[k]=a[k];
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<j;k++){
                s+=b[j]-b[j-1];
                b[k]=b[j];
            }
            if(s>m){
                mx=max(j-i,mx);
                break;
            }
        }
    }
    return mx;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n+1,cmp);
    cout<<c();
    return 0;
}
