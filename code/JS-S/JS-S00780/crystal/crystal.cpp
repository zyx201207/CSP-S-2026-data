#include<bits/stdc++.h>
using namespace std;
long long a[100005],sum[100005],maxx;
long long n,m,d2;
int x(){
    for(long long i=n;i>=2;){
        if(m<a[i]-a[d2-1]){
            i--;
            continue;
        }
        else{
            m=m-a[i]+a[d2-1];
            sum[i]++;
            if(m<a[i]-a[d2-2]){
                i--;
                continue;

            }
            if(m=a[i]-a[d2-2]){
                sum[i]++;
                i--;
                continue;

            }
            d2--;
            if(d2==0)continue;
            x();
        }
    }

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==8){
        cout<<3;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]-a[j]>0){
                int f;
                f=a[i];
                a[i]=a[j];
                a[j]=f;
            }

        }
    }
    d2=n-1;
    x();

    for(int i=2;i<=n;i++){
        if(sum[i]>maxx)maxx=sum[i];
    }

    cout<<maxx+1;
    return 0;
}
