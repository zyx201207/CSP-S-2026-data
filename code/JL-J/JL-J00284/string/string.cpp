#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,n[1001],sum=0,sum1=0,b;
    char m[1001];
    cin>>a;
    for(long long i=0;i<a;i++){
        cin>>n[i]>>m[i];
        sum1+=n[i];
    }
    b=sum1/2;
    for(long long i=0;i<b;i++){
        if(m[i]!=m[sum1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
