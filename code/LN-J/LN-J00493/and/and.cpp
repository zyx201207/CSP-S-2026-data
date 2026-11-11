#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
bool cmd(int a,int b){
    return a>b;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1,cmd);
//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
ans=a[1];
int flag=1;
int counting=1;
for(int i=2;i<=n;i++){
    //cout<<ans<<' '<<a[i]<<' '<<(ans&a[i])<<' '<<counting<<' '<<endl;
    if(counting==m)break;
    if((ans&a[i])==0){
        counting=1;
        ans=a[i];
        flag=i;
        //cout<<1<<endl;
    }//lse cout<<0<<endl;
    if(((ans&a[i])!=0)&&(i!=2))counting++;
}
//cout<<flag<<endl;
for(int i=flag+1;i<=n;i++){
    int x=(ans&a[i]);
       // cout<<ans<<' '<<a[i]<<' '<<x<<' '<<m<<endl;
    if(!(m-1))break;
    if(x==0){
        continue;
    }
   // cout<<1<<' ';
    ans&=a[i];
    m-=1;
}

cout<<ans;
return 0;
}
