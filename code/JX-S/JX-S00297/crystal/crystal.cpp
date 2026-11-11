#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long d[500010];
long long ax[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ax[i]=a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int k=n;k>=1;k--){
        for(int i=1;i<=n;i++){
            ax[i]=a[i];
        }
        int mx=m;
        memset(d,0,sizeof(d));
        d[k]=0;
        for(int i=1;i<=k-1;i++){
            d[i]=ax[k]-ax[i];
        }


    //for(int i=1;i<=k;i++)cout<<d[i]<<endl;


        int j=k-1;
        long long sum=1;
        while(mx>=d[j]&&j>=1){
            mx-=d[j];
            //ax[j]=ax[k];
            j--;
            sum++;
        }
        ans=max(ans,sum);

        if(ans>=k){
            break;
        }
    //cout<<endl<<ans<<endl<<endl;


    }
    cout<<ans;
    return 0;
}
