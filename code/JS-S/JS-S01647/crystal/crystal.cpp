#include<bits/stdc++.h>
using namespace std;

long long a[10000005];
bool cmp(int x,int y){
    return x<y;
}
long long ans=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);

    long long b[1000005];
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
    }

    for(int i=1;i<=n;i++){
        if(m<=0)break;
        if(b[1]==0 or b[n-1]==0)continue;

        if(abs(b[i+1]-b[i])<abs(b[n-i]-b[n-i-1])){
            for(int j=1;j<=n;j++){
                if(a[j+1]<a[j] and m>=(a[j+1]-a[j])){
                    m-=(a[j+1]-a[j]);
                    a[j]=a[j+1];
                }
                if(m<=0)break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(m<=0)break;
        if(abs(b[i+1]-b[i])>abs(b[n-i]-b[n-i-1])){
            for(int j=n;j>=1;j--){
                if(a[j]>a[j-1] and m>=(a[j]-a[j-1])){
                    m-=(a[j]-a[j-1]);
                    a[j-1]=a[j];
                }
                if(m<(a[j-1]-a[j-2]))break;
                if(m<=0)break;
            }
        }
    }


    for(int i=1;i<=n;i++){
        if(m<=0)break;
        if(abs(b[i+1]-b[i])==abs(b[n-i]-b[n-i-1])){
            for(int j=n;j>=1;j--){
                if(a[j]>a[j-1] and m>=(a[j]-a[j-1])){
                    m-=(a[j]-a[j-1]);
                    a[j-1]=a[j];
                }
                if(m<(a[j-1]-a[j-2]))break;
                if(m<=0)break;
            }
        }
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-1;i++){
        if(a[i]==a[i+1])ans++;
    }
    cout<<ans<<'\n';

    return 0;
}
