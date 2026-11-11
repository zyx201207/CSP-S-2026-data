#include<bits/stdc++.h>
using namespace std;
long long n,m,a[6005],s[6005][6005],cz[6005];
int mx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=1,f1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)f=0;
        if((a[i+1]-a[i]!=a[i]-a[i-1]&&i>=2&&i<=n-1)||i==1||i==n)f1=0;
    }
    if(f){
        int i=1;
        while(i*(i-1)/2<=m){
            i++;
        }
        cout<<i-1;
        return 0;
    }
    if(f1){
        int i=1;
        while(i*(i-1)/2*(a[2]-a[1])<=m){
            i++;
        }
        cout<<i-1;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        cz[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            s[i][j]=s[i-1][j-1]+j*cz[i];
            if(s[i][j]<=m){
                mx=max(mx,j+1);
            }
        }
    }
    cout<<mx;
return 0;
}
