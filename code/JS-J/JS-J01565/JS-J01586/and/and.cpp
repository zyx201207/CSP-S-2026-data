#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }else if(m==2){
        int mx=INT_MIN;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }else if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
    }else{
        sort(a+1,a+n+1);
        int su=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            su=su&a[i];
        }
        cout<<su;
    }
    return 0;
}
