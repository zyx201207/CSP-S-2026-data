#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        int ma=-1;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            ma=max(x,ma);
        }
        cout<<ma;
        return 0;
    }
    else if(m==n){
        int ma=2147483647;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            ma&=x;
        }
        cout<<ma;
        return 0;
    }
    else if(m==2){
        int ma=-1;
        int a[2000];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(a[i]&a[j],ma);
            }
        }
        cout<<ma;
        return 0;
    }
    else {
        int a[200005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int sum=2147483647;
        for(int i=n;i>=m;i--){
            sum&=a[i];
        }
        cout<<sum;
    }
    return 0;
}
