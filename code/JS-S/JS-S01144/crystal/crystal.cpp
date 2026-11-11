#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    a.resize(n+5);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    long long s=a[(n/2)+1]-a[n/2];
    int cnt=1;
    while(m){
       m-=2*s;
       if(m<=0 && m+s>=0){
            cnt+=1;
            break;
       }
       else if(m<=0){
            break;
       }
       s++;
       cnt+=2;

    }
    cout<<cnt;
    return 0;
}
