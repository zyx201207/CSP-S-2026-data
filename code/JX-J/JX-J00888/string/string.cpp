#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
ll n,ans=0;
struct node{
    ll num;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i].num=read();
        char ch=getchar();
        while(ch<'a'||ch>'z')ch=getchar();
        a[i].c=ch;
    }
    ll l=1,r=n;
    while(l<r){
        ll val=min(a[l].num,a[r].num);
        a[l].num-=val;
        a[r].num-=val;
        if(a[l].c!=a[r].c){
            ans+=val;
        }
        if(a[l].num==0){
            l++;
        }
        if(a[r].num==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
