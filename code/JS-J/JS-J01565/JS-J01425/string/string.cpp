#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e5+10;
ll a[N];
char c[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int i=0,j=n+1;
    ll l=0,r=0,cnt=0;
    while(i+1<j){
        if(l<=r){
            i++;
            l+=a[i];
            ll t=min(l,r);
            if(j!=n+1&&c[i]!=c[j])cnt+=t;
            l-=t,r-=t;
        }
        else{
            j--;
            r+=a[j];
            ll t=min(l,r);
            if(i!=0&&c[i]!=c[j])cnt+=t;
            l-=t,r-=t;
        }
    }
    cout<<cnt;
    return 0;
}
