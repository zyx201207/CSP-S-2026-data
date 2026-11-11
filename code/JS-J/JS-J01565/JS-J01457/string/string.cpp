#include<bits/stdc++.h>
using namespace std;
#define ll long long
char st[200005];
ll s[200005];
inline ll read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,l=0;
    ll x;
    char y;
    n=read();
    for(int i=1;i<=n;i++){
        x=read(),y=read();
        st[i]=y,s[i]=x;
        l+=x;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    char t=st[1];
    bool check=true;
    for(int i=2;i<=n;i++){
        if(t!=st[i]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<0;
        return 0;
    }
    cout<<l/2;
    return 0;
}
