#include<bits/stdc++.h>
using namespace std;
const long long M=5000000;
long long a[M];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;


    bool pd=false;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(i>=1&&a[i]-a[i-1]<0){
            pd=true;
        }
    }
    if(pd==true){
        sort(a,a+n);
    }

    long long ans=0,cnt=0;
    long long maxn=0;
    for(long long i=n-1;i>=0;i--){
        cnt=0;
        ans=0;
        for(long long j=i-1;j>=0;j--){
            if(ans>=m){

                if(maxn<cnt){
                    maxn=cnt;

                }
                continue;
            }
            else{
                cnt+=1;
                ans=ans+(a[i]-a[j]);

            }
        }
        if(maxn<cnt){
            maxn=cnt;

        }
    }
    cout<<maxn;

    return 0;
}
