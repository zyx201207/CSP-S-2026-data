#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long cnt=0,ans=0;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
    }
    int c=1;
    long long sum2=0,m2;
    m2=m;
    for(int i=n;i>=1;i--){
        //out<<1<<" "<<m<<endl;
        m=m2;
        c=1;
        cnt=0;
        sum2=0;
        while(m>=0){
            b[i]=0;
            for(int j=i-c;j<=i;j++){
                sum2=sum2+b[j];
            }
            if(sum2<=m){
                cnt++;
                c++;
                m=m-sum2;
                //cout<<m<<endl;
                sum2=0;
            }else{
                ans=max(ans,cnt);
                break;
            }
            if(c>=i){
                ans=max(ans,cnt);
                break;
            }
        }
    }
    cout<<ans+1;
    return 0;
}
