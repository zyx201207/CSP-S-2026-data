#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,l,r;
    char c;
}s[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long last=1;
    for(long long i=1;i<=n;i++){
        cin>>s[i].x>>s[i].c;
        s[i].l=last;
        s[i].r=last+s[i].x-1;
        last+=s[i].x;
    }
    last--;
    long long lp=1,rp=n,ans=0;
    while(lp<rp){
        long long tmp=min(s[lp].x,s[rp].x);
        s[lp].x-=tmp;
        s[rp].x-=tmp;
        if(s[lp].c!=s[rp].c){

            ans+=tmp;
        }
        if(s[lp].x==0)lp++;
        if(s[rp].x==0)rp--;
    }
    cout<<ans;
    return 0;
}
