#include<bits/stdc++.h>
using namespace std;

int n,ans=-1;
long long a[500010];
unsigned long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        long long k=m;
        int cnt=1,j=i;
        bool f=0;
        while(k>=0&&j<n&&!f){
            if((a[j+1]-a[j])*cnt<=k){
                k-=(a[j+1]-a[j])*cnt;
                cnt++;
                j++;
            }
            else  f=1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

