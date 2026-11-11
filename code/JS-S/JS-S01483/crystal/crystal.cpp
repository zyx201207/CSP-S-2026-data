#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
         b[i]=a[i]-a[i-1];

         }
     int cnt=1;
     for(int i=2;i<=n;i++){
            if(m-b[i]*(i-1)>=0){
                m-=b[i]*(i-1);
                cnt++;
        }
        else{
            cout<<cnt;
            return 0;
        }
     }
    cout<<cnt;
    return 0;
}
