#include<bits/stdc++.h>
using namespace std;
const int mxn=5e5+10;
long long n,m;
long long a[mxn],sum[mxn],w[mxn];
long long ans,tep=0;
bool cmp(int a,int b){
    return a<b;
}
int main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
  freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ans=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]-a[i-1];
    }
    if(sum[1]<0)sum[1]=0;
    sort(sum+1,sum+n+1,cmp);
    for(int i=1;i<=n;i++){
        w[i]=sum[i-1]+sum[i];
    }
    for(int i=1;i<=n;i++){
        if(sum[i]!=sum[i+1] and sum[i+1]!=sum[i+2]){
            ans-=w[i];
        tep=i;
        if(ans<w[i+1]){

            break;
            }
        }
        else{
            ans-=(i*sum[i+1]);
            tep++;
            if(ans<0){
                break;
            }
        }
    }
    cout<<tep;
}
