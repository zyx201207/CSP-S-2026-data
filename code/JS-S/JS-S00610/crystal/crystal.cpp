#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a[500005],b[500005],n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    long long sum=0,s=1,ss=1,h=1,j=0;
    for(int i=1;i<=n;i++){
        if(m<0||i==n){
            if(s-1>ss)ss=s-1;
            while(m<0){
                s--;
                m+=sum;
                sum-=b[h++];
            }

        }else{
            m-=b[i]*(i-h+1);
            s++;
            sum+=b[i];
        }
    }
    cout<<ss;
    return 0;
}
