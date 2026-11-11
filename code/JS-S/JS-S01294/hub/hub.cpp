#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v;
int read(){
    int x=0,f=1;
    char ch=getchar();
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

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),k=read();
        for(int i=1; i<n; i++) u=read(),v=read();
        int x=n/2-k;
        if(x%4==0) cout<<x/4+1<<endl;
        else cout<<x/4+2<<endl;
    }
    return 0;
}