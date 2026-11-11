#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct nod{
    ll x,y;
}a[200005];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){f=-1;}
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
ll len(ll x){
    ll cnt=0;
    while(x){
        if((x&1)==1){
            cnt++;
        }
        x=x>>1;
    }
    return cnt;
}
bool cmp(nod xx,nod yx){
	if(xx.y>yx.y){
		return xx.x>xx.y;
	}
    return xx.x>yx.x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i].x=read();a[i].y=len(a[i].x);
    }
    sort(a+1,a+n+1,cmp);
    /*for(int i=1;i<=n;i++){
		cout<<a[i].x<<":"<<a[i].y<<" ";
	}*/
    if(m==1){
        cout<<a[1].x;
        return 0;
    }
    if(m==2){
        cout<<((a[1].x)&(a[2].x));
        return 0;
    }
    ll ans=a[1].x&a[2].x;
    for(int i=3;i<=m;i++){
        ans=ans&a[i].x;
    }
    cout<<ans;
    return 0;
}

