#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N],m,ans1=(1<<31)-1,ans=ans1,c[N];
ll b[30]={1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12,1<<13,1<<14,1<<15,1<<16,1<<17,1<<18,1<<19,1<<20,1<<21,1<<22,1<<23,1<<24,1<<25,1<<26,1<<27,1<<28,1<<29,1<<30};
int smof1(ll x){
    int res=0;
for(int i=0;i<30;i++){
    res+=x&b[i];
}return res;
}
int lenofs(ll x){
    int cnt=0;
for(int i=0;i<30;i++){
    cnt+=(x>>i+1==0?0:1);
}return cnt;
}
bool cmp(ll x,ll y){
if(lenofs(x)==lenofs(y))smof1(x)>smof1(y);
return lenofs(x)>lenofs(y);
}
int main(){
    //and
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
int m_=m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    c[i]=a[i];
}
sort(a+1,a+n+1,cmp);
sort(c+1,c+n+1,greater<ll>());
int j=1;
while(m_--){
    ans&=c[j];
    ans1&=a[j++];
}cout<<max(ans,ans1);
      return 0;
}
