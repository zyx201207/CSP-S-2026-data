#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
inline int read(){
    char ch=getchar();int f=1,k=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){k=(k<<1)+(k<<3)+ch-'0';ch=getchar();}
    return k*f;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n;
    n=read();
    int c,t;
    c=read();
    t=read();
    while(t--){
        int n=read(),k=read();
        rep(i,0,n*2-2)int a=read();
        cout<<(n-d)/d<<endl;
    }
}
/*
154099
first,i can't solve this problem
as the oler Simon said on the bus:"why not put '154099' at the end of T4",
so i put it here
15 means simon
and 40 means his girlfriend
*/
