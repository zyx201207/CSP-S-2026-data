#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }else if(m==2){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
    }else if(m==n){
        long long cnt;
        for(int i=2;i<=n;i++){
            cnt=cnt&a[i];
        }
        cout<<cnt;
    }
    sort(a+1,a+n+1);
    long long cnt;
    for(int i=n;i>=n-m+1;i--){
        if(i==n)cnt=a[i];
        else cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}
