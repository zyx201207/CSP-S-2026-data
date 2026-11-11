#include<bits/stdc++.h>
using namespace std;
long long m,n,x,ans=0,p1=0;
bool flag[3000002][100];
long long cnt[100];
long long a[3000000];
map<long long,bool>zxc;
struct node{
bool qwe[65];
}asd[3000000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>x;
    a[i]=x;
    long long p=0;
    while(x){
        flag[++p][i]=x%2;
        if(x%2)cnt[p]++,asd[i].qwe[p]=1;
        x/=2;

    }
    p1=max(p,p1);
}
//for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
for(int i=1;i<=p1;i++){
    if(cnt[p1-i+1]<m)continue;
    ans+=(long long)pow(2,(p1-i));
    for(int j=1;j<=n;j++){
        if(flag[p1-i+1][j]==0&&(!zxc[j])){
           zxc[j]=1;
            for(int k=1;k<=p1;k++){
                if(asd[j].qwe[k]==1)cnt[k]--;
            }
        }
    }
    //cout<<ans<<" ";
}
cout<<ans;
return 0;
}
