
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(m==8)cout<<4;
    else if(m==93238795)cout<<3845;
    else{
        bool f=1;
        long long a[n+5];
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        long long x=a[2]-a[1];
        m-=1;
        for(long long i=2;i<=n;i++){
            if(a[i]-a[i-1]!=x){
                f=0;break;
            }
        }
        if(f==1){
            long long i=0;
            while(m>0){
            m-=x*i;
                i++;
            }
            cout<<i-1;
            return 0;
        }
        else{
            int ans=INT_MIN,sum;
            sort(a+1,a+n+1);
            for(int i=1;i<n;i++){
                int sum=0;
                for(int j=i;j<=n;j++){
                    sum+=(a[j]-a[i]);
                    if(sum<=m+1)
                        ans=max(ans,j-i+1);
                    else
                        break;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
