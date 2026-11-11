#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct sts{
int x;char c;
}a[N];
ll n,cnt,ans;
char mid;
void f(ll x,ll y,int k){
    int i=k,j=k;
while(x&&y){
    if(x>y){
    if(a[i].c!=a[j].c){
        ans+=x-y;
    }
    x-=y,y=a[++j].x;
    }else if(x<y){
    if(a[i].c!=a[j].c){
        ans+=y-x;
    }
    y-=x,x=a[++i].x;
    }else{
        if(a[i].c!=a[j].c){
        ans+=x;
    }x=a[++i].x,y=a[++j].x;
    }
}return;
}
int main(){
    //string
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
    int x;char c;
    cin>>x>>c;
    cnt+=x;
    a[i].x=x,a[i].c=c;
}
if(cnt&1){
    ll num=0,zzz=0;
    for(int i=1;i<=n;i++){
        num+=a[i].x;
        if(num>cnt/2)f(num-(cnt/2),a[i].x-(num-(cnt/2))-1,i);
    }
}else{
    ll num=0,zzz=0;
    for(int i=1;i<=n;i++){
        num+=a[i].x;
        if(num>=cnt/2)f(num-(cnt/2),a[i].x-(num-(cnt/2)),i);
    }
}cout<<ans;
      return 0;
}
