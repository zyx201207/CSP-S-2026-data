#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005];
int n,m;
int ans=0;
bool flag1=true,flag2=true;
bool cmp(int a,int b){
    return a>b;
}
bool eryi(int x){
    while(x!=0){
        if(x%2==0) return false;
        else x/=2;
    }
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2) sum[i]=a[i]&sum[i-1];
        else sum[i]=a[i];
        ans=max(ans,a[i]);
        if(a[i]!=i-1) flag1=false;
    }
    sort(a+1,a+n+1,cmp);
    if(m==n){
        cout<<sum[n];
    } else if(m==1) {
        cout<<ans;
    } else if(flag1==true||flag2==true){
        for(int i=2;i<=m;i++){
            a[i]&=a[i-1];
        }
        cout<<a[m];
    } else if(m==2){
        int aans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;i<=n;j++){
                aans=max(aans,a[i]&a[j]);
            }
        }
        cout<<aans;
    }
    return 0;
}
