#include<bits/stdc++.h>
using namespace std;
int f(int x){
    int ans=0;
    while(x>0){
        if(x%2==1){
            ans++;
            x=(x-1)/2;
        }else{
            x/=2;
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[205];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f(a[j])<f(a[j-1])){
                int c=a[j];
                a[j]=a[j-1];
                a[j-1]=c;
            }
        }
    }
    for(int i=n;i>=n-m+1;i--){
        if(i==n){
            sum=a[i];
        }else{
            sum=sum & a[i];
        }
    }
    cout<<sum;
    return 0;
}
