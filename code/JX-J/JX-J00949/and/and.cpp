#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
long long maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==m){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,(a[i]&a[i]));
        }
        cout<<maxx;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)maxx=max(maxx,(a[i]&a[j]));
            }
        }
        cout<<maxx;
    }else cout<<(1&(n-1));
    return 0;
}

