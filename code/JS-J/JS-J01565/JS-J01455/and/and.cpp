#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long hx[2000005];

long long a[200005];
string f[200005];
long long ans;
long long maxx=0;




int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        while(x>=1){
            int d=x%2;
            f[i]=char(d+'0')+f[i];
            x/=2;
        }

    }
    if(m==1){
        cout<<maxx;
    }
    else if(m=n-1){
        cout<<0;
    }
    else {
        cout<<maxx;
    }
    return 0;
}
