#include<bits/stdc++.h>
using namespace std;
#define ll long long 

inline ll re(){
    ll a=0,s=1;char d=getchar_unlocked();
    while(!isdigit(d)){
        if(d=='-') s=-1;
        d=getchar_unlocked();
    }
    while(isdigit(d)){
        a=(a<<3)+(a<<1)+d-48;
        d=getchar_unlocked();
    }
    return a*s;
}

int a,ans;
ll x[500001],z[500001],q[500001],h[500001],s;//qianzhuihe&&houzhuihe

void sol(){
    int l,r,mid;ll v;
    for(int i=1;i<=a-1;i++){
        l=i,r=a-1,mid=(l+r)>>1;
        v=q[mid]-q[i-1]+(1-i)*(h[i]-h[mid+1]); 
        // printf("i=%d\n",i);
        while(l<r){
            // printf("i=%d l=%d r=%d mid=%d    v=%lld\n",i,l,r,mid,v);
            if(v==s){
                while(z[mid+1]==0) mid++;
                ans=max(ans,mid-i+1);
                // printf("mid=%d i=%d ans=%d\n",mid,i,ans);
                break;
            }
            else if(v<s) ans=max(ans,l-i+1),l=mid+1;
            else r=mid;
            mid=(l+r)>>1;
            v=q[mid]-q[i-1]+(1-i)*(h[i]-h[mid+1]);
        }
        // printf("l=%d r=%d i=%d v=%lld ans=%d\n",l,r,i,v,ans);
        if(v<s) ans=max(ans,l-i+1);
    }
    return ;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    a=re(),s=re();
    for(int i=1;i<=a;i++) x[i]=re();
    sort(x+1,x+1+a);
    for(int i=1;i<a;i++) z[i]=x[i+1]-x[i],q[i]=q[i-1]+z[i]*i;
    for(int i=a-1;i>=1;i--) h[i]=h[i+1]+z[i];
    sol();
    printf("%d \n",ans+1);
    return 0;
}

/*
froepen frepoen
int mian();
printf("%d /n",n);
X X XXX

X X X XX X X X XXXX X X X XX X X X XXXX
X X X XX X X X XXXX X X X XX X X X --->

//freopen

Never_Gonna_Give_You_Up

zhi ci jian wo zhi jue liu nian ying you xian ~

qian nian zhi hou hai sheng xia shen me ?

Again and again I signed~

Mili NB!

*/