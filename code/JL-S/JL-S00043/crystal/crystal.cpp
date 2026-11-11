#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long mf=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        int ans=1,y=1,t;
        m=mf;
        for(int j=1;j<=mf;j++){
            if(j==1){
                t=a[i-y];
            }
            if(t==a[i]){
                ans++;
                y++;
                t=a[i-y];
            }
            if(i==y||m==0){
                break;
            }
            if(t+1==a[i]){
                ans++;
                m--;
                y++;
                t=a[i-y];
            }
            else{
                t++;
                m--;
            }
        }
        b[i]=ans;
    }
    int sum=-1;
    for(int i=1;i<=n;i++){
        sum=max(b[i],sum);
    }
    cout<<sum;
    return 0;
}
