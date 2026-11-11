#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,a[200000+10],tmax[200000+10],sum;
bool b[200000+10];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
   for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        sum=0;
        if(i==1&&b[j]==false){
            sum=a[j];
            if(sum>=tmax[1]){
                tmax[1]=sum;
            }

        }else{

            if(b[j]==false){
                sum=tmax[i-1]&a[j];
                if(sum>=tmax[i]){
                    tmax[i]=sum;
                }

            }

        }
    }
    for(int j=1;j<=n;j++){
                if(a[j]==tmax[i]){
                    b[j]=true;
                }
            }
   }
   cout<<tmax[m];
    return 0;
}
