#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
#define ll long long
ll n,m,sum=0;
int ans=1,num=1;
ll a[N],b[N],c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) b[i]=b[i-1]+c[i];
    sum=0,num=1,ans=1;
    int k=1;
    for(int i=2;i<=n;i++){
        sum+=c[i]*(i-k);
        //cout<<sum<<"\n";
        if(m>=sum){
            num++;
        }else{
            ans=max(ans,num);
            while(m<sum&&num){
                sum-=b[i]-b[k];
                num--;
                k++;
            }
            num++;
        }
        ans=max(ans,num);
        //cout<<i<<" "<<sum<<" "<<num<<"\n";
    }
    cout<<ans;
    return 0;
}
