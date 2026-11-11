#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5],cnt=0,maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]==i-1){
            continue;
        }else{
            flag=1;
        }
    }
    if(flag==0){
        cout<<n-m;
        return 0;
    }
    if(1==m){
        int maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(n==m){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        int ans=0,max1=0;
        for(int i=1;i<=n;i++){
            ans=sum|a[i];
            max1=max(max1,ans);
        }
        cout<<max1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cnt=a[i]&a[j];
            maxn=max(maxn,cnt);
        }
    }
    cout<<maxn;
}
