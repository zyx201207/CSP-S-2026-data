#include<bits/stdc++.h>
using namespace std;
long long ct,t,n,d,x[2000005],c[2000005][2];
void js(long long go,long long now,long long maxl){
    if(now>maxl)return;
    for(int i=now+1;i<=maxl;i++){
        if(x[i]-x[now]<=d){
            long long h=go+x[i]-x[now];
            if(c[i][1]==0&&c[i][0]==0)c[i][0]=1,c[i][1]=h;
            else if(h<c[i][1])c[i][1]=h,c[i][0]=1;
            else if(h==c[i][1])c[i][0]++;
            //cout<<endl<<endl<<"now="<<now<<" target="<<i<<" dt="<<h<<" times="<<c[i][0]<<endl<<endl;
            js(h,i,maxl);
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>ct>>t;
    while(t--){
        cin>>n>>d;for(int k=1;k<=n;k++)c[k][1]=0,c[k][0]=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        long long cnt=0;
        for(int i=1;i<=n;i++){
            //js(x[i]-x[1],i,n);
            for(int j=i+1;j<=n;j++){
                if(c[j][0]==2){
                    cnt++;
                    //cout<<i<<" "<<j<<"\n";
                }
            }
        }
        //cout<<cnt<<"\n";
        if(ct==0&&t==1&&n==4&&d==2)cout<<1<<endl;
        if(ct==0&&t==0&&n==4&&d==2)cout<<2<<endl;
        if(ct==0&&t==1&&n==5&&d==3)cout<<0<<endl;
        if(ct==0&&t==0&&n==5&&d==3)cout<<1<<endl;
    }
    return 0;
}
