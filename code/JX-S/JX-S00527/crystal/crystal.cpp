#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){\
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long c=a[2]-a[1];
    int cnt=1;
    while(m){
        if(m-c>=0){
            m-=c;
            c*=2;
            cnt++;
        }
        else{
            m=0;
        }
    }
    cout<<cnt;
    return 0;
}
