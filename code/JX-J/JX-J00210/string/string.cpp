#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum2,sum[200005],sum1[200005],x[200005],x1[200005],j=1;
char c[200005],c1[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
        sum[i]=sum[i-1]+x[i];
    }
    for(int i=n;i>=1;i--){
        x1[i]=x[n-i+1];
        c1[i]=c[n-i+1];
    }
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+x1[i];
    }
    //for(int i=1;i<=n;i++)cout<<x[i]<<" "<<c[i]<<" ";
    //cout<<"\n";
    //for(int i=1;i<=n;i++)cout<<x1[i]<<" "<<c1[i]<<" ";
    long long i=1;
    while(1){
        if(c[i]!=c1[j]){
            n=n;
        }
        else{
            ans+=min(sum[i],sum1[j])-max(sum[i-1],sum1[j-1]);
        }
        if(sum[i]>=sum1[j]){
            j++;
        }
        else{
            i++;
        }
        if(i==n and j==n+1)break;
    }
    cout<<(sum1[n]-ans)/2;
    return 0;
}

