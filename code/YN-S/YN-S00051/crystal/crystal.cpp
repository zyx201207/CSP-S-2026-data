#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
struct node{
    ll ca,da,ans;
};
node b[N];
ll a[N],n,m,mx;
int main(){
     freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int flag=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int k=a[2]-a[1];
    for(int i=1;i<=n;i++)
    if(a[i]-a[i-1]!=k)
        flag=1;
    if(flag==1){
    ll cnt=0,sum=0;
    for(int i=1;i<=n;i++){
    sum+=a[i];
    if(a[i]!=a[i-1]){
    cnt++;
    b[cnt].da=a[i];
    b[cnt].ca=a[i]*i-sum;
    b[cnt].ans=i;}
    if(a[i]==a[i-1]){
    b[cnt].ans++;}
    }
    for(int i=1;i<=cnt;i++){
    if(b[i].ca<=m)
    mx=max(mx,b[i].ans);
    int cnt1=0;
    if(b[i].ca>m){
    while(b[i].ca>m){
    cnt1++;
    b[i].ca=b[i].ca-(b[i].da-a[cnt1]);
    b[i].ans--;}
    mx=max(mx,b[i].ans);
    }
    }
    cout<<mx;}
    if(flag==0){
    ll cnt2=0,mn=1;
    while(m){
    mn++;
    cnt2++;
    m=m-cnt2*k;
    }
    cout<<mn;
    }
    return 0;
}
