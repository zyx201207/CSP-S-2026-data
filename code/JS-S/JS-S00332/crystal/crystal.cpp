#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1,k;
const long long N=5e5+10;
struct s{
    long long v,cha;
}a[N];
bool cmp1(s a,s b){
   return a.v<b.v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
        k=abs(a[i].v-a[i-1].v);
    }
    sort(a+1,a+n+1,cmp1);
    int b=1;
    while(m>0){
       if(cnt*k<=m){
         //a[cnt].v+=k;
         m-=k*cnt;
         cnt++;
       }else{
          cout<<cnt;
          return 0;
       }

    }
    cout<<cnt;
    return 0;
}
