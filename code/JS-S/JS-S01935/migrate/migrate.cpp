#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int read(){
    int x=0,f=1;
    char ch;
    ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){ 
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int n,m;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(a[2]-a[1]>=d) {
            cout<<0<<endl;
        }else {
            cout<<n-(d/(a[2]-a[1])+1)<<endl;
        }
    }
}
