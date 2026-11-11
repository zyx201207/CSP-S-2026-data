#include<bits/stdc++.h>
using namespace std;
long long n,m,a[222222],maxn=-2e9,pick[222222];
bool cmp(int x,int y){
return x>y;
}

int main(){


freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];


}
sort(a+1,a+n+1,cmp);
maxn=a[1];
pick[1]=1;
for(int w=1;w<m;w++){
        int ma=-1;
for(int i=1;i<=m;i++){
    if(maxn&a[i]>=ma&&pick[i]==0){}
    pick[i]=1;
    ma=maxn&a[i];
}
maxn=ma;
}
cout<<maxn;

return 0;
}
