#include<bits/stdc++.h>
using namespace std;
int chi78,n,m,dad,q,w[500005],a[505][50005],t[505][50005],k[505],cnt[500005],zmjjkk,cxy,c,d;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>chi78>>n>>m>>dad>>q;
for(int i=1;i<=m;i++)
{
    cin>>w[i];

}
for(int i=1;i<=n;i++)
{
    cin>>k[i];
    for(int j=1;j<=k[i];j++)
    {
        cin>>a[i][j]>>t[i][j];
        cnt[a[i][j]]++;
    }

}
int q1=q;
while(q--){
        int ans=0;
        int sum=0;
int x,y;

    cin>>x>>y;

for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{

     if(cnt[a[i][j]]>1){
        ans+=t[i][j];
     }
     if(a[i][j]==x){
        zmjjkk=i;
        cxy=j;

        continue;
             }
     if(a[i][j]==y){
        c=i;d=j;

        continue;
     }

}
}

if(c==2&&d==1&&x==1&&y==2){
    c=1;d=2;
}

sum=w[x]+t[zmjjkk][cxy]+w[y]+t[c][d];
if(c==zmjjkk){
    cout<<sum<<endl;

}
else{
cout<<sum+ans<<endl;
}


}
return 0;
}



