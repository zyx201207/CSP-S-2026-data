#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool x=false;
long long b;
long long sum=1,ans=0,num=0;
bool cmp(int a,int b){
    if(a>b) return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if(a[i]==a[j]){
                x=true;
                sum++;
                b=a[i];
            }
        }
    }
    if(x){
        for(long long i=n-1;i>0;i--){
            if(a[i]<b){
                ans+=a[i];
                num++;

            }
        }
        if(ans+m>=sum*b){
         cout<<num+sum;
        }
    }
    else{
        for(long long i=0;i<n;i++){
            if(a[i]<a[n/2]){
                ans+=a[i];
                num++;

            }
        }
        if(ans+m>=a[n/2]){
         cout<<num+sum;
        }
    }
    return 0;
}
