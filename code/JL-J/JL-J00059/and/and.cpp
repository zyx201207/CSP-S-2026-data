#include<bits/stdc++.h>
using namespace std;
int a[100005];//er jin zhi
int b[100005];//lin shi
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int ai=1;
    for(int i=2;i<=n;i++){
        int t,ans=0,x=1;
        cin>>a[i];
        while(max(a[i],a[i-1])>=0){
            //for(int j=1;i<=m;i++){
                if(a[i-1]%2==a[i]%2){
                    b[x]=1;
                }
                else b[x]=0;
                a[i]/=2;
                b[i-1]/=2;
                x++;
           // }
        }
        int ii=1,pw=1;
        for(int j=x;j>=1;j++,ii++){
            ans+=a[i]*pw;
            pw*=10;
        }
        a[ai]=ans;
   }
   cout<<a[1];
   return 0;
}
