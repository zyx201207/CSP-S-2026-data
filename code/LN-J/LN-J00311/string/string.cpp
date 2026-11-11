#include<bits/stdc++.h>
using namespace std;
typedef long long la;
inline la read(){
    la ret,flag=1;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')flag=-1;
    ret=(la)ch-'0';
    while(isdigit(ch=getchar()))ret=ret*10+(la)ch-'0';
    return ret*flag;
}
const int N=2e5+10;
la lt[N],rt[N],n;char ch[N];
int find(la x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(x>rt[mid])l=mid+1;
        else if(x<lt[mid])r=mid-1;
        else return mid;
    }
    return l;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        int tin=read();cin>>ch[i];
        lt[i]=rt[i-1]+1;
        rt[i]=rt[i-1]+tin;
    }
    la l=1,r=rt[n],ans=0;
    while(l<=r){
        int lp=find(l),rp=find(r);la delta;
        if(rt[lp]>=rt[n]-lt[rp]+1){
            delta=r-lt[rp]+1;
            r=lt[rp]-1;
            l=rt[n]-r+1;
        }else{
            delta=rt[lp]-l+1;
            l=rt[lp]+1;
            r=rt[n]-l+1;
        }
        if(ch[lp]!=ch[rp])ans+=delta;
    }
    printf("%lld",ans);
    return 0;
}
