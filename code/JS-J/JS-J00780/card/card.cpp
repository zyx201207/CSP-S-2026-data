#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c[300010],x,y,z,t,k;
bool d[300010];
int main(){
   // freopen("card.in","r",stdin);
   // freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    k=n;
    while(k--){
        for(int i=1;i<=n;i++)b[i]=0;
        for(int i=1;i<=m;i++)d[i]=0;
        x++;y=0;
        for(int i=x;i<=n;i++){
            t=0;
            y++;
            if(!d[i]){
                b[y]=a[i];
                d[i]=1;
            }
            else{
                for(int j=1;j<=y;j++){
                    if(t==1){
                        for(int l=x;l<=n;l++)if(a[l]==b[j]){d[l]=0;break;}
                        b[j]=0;
                    }
                    if(b[j]==a[i]){t=1;z=j+1;}
                }
                y=z;
            }
        }
        for(int i=1;i<=n;i++)if(d[i]==1)c[a[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}
