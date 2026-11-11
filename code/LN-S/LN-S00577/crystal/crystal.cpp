#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==2){
        if(m>=abs(a[2]-a[1]))
            cout<<2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    cout<<endl;
    long long x=abs(a[2]-a[1]);
    cout<<x<<' ';
    long long s=0;
    cout<<s<<' ';
    long long cnt=0;
    cout<<cnt<<' ';
    long long t=1;
    cout<<t<<' ';
    cout<<endl;
    while(s<=m){
        t*=x;
        cout<<t<<' ';
        s+=t;
        cout<<s<<' ';
        cnt++;
        cout<<cnt<<' '<<endl;
    }
    if(cnt>=n)
        cnt=n;
    cout<<cnt;
    return 0;
}
