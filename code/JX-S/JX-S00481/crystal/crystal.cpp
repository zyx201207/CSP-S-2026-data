#include<iostream>
#include<climits>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int n,m,a[500010],mid=LLONG_MAX,ans,num,cnt,mid1,pl;
bool v,vp;
struct node{
int id,it;
}b[500010];
bool cmp(node a,node b){
    return a.it<b.it;
}
signed main(){
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]!=i)v=1;
    if(i){
        if(a[i]-a[i-1]!=pl){
          vp=1;  
        }pl=a[i]-a[i-1];
    }
    cnt+=a[i];
}
if(!v||!vp){
    mid=cnt/n;
for(int i=0;i<n;i++){
    b[i].it=(mid>=a[i]?mid-a[i]:INT_MAX);
    b[i].id=i;
}
sort(b,b+n,cmp);
for(int i=0;i<n&&m>=b[i].it;i++){
if(m>=b[i].it){
    m-=b[i].it;
   ans++;
}
}
cout<<ans<<endl;
    return 0;
}
sort(a,a+n);
int ans1=0;
int tyyy=m;
for(int md=0;md<n;md++){
    m=tyyy;
    ans=0;
mid=a[md];
for(int i=0;i<n;i++){
    b[i].it=(mid>=a[i]?mid-a[i]:INT_MAX);
}
sort(b,b+n,cmp);
for(int i=0;i<n&&m>=b[i].it;i++){
if(m>=b[i].it){
    m-=b[i].it;
   ans++;
}
}
ans1=max(ans1,ans);
}
cout<<ans1<<endl<<cnt;
    return 0;
}