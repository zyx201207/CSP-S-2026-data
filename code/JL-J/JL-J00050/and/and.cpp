#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0,};
long long n,m,sum,sum1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
if(m==1){
    sort(a+1,a+1+n);
    cout<<a[n];
    return 0;
}
else if(m==n){
        sum=a[1];
    for(long long i=2;i<=n;i++){
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
else if(m==2){
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            sum=max(sum,a[i]&a[j]);
        }
    }
    cout<<sum;
    return 0;
}
else if(m==n-1){
    for(long long i=1;i<=n;i++){
        a[0]=a[n];
            long long num=a[i-1];
        for(long long j=1;j<=n;j++){
            if(j!=i){
                num=num&a[j];
            }
        }
    sum=max(sum,num);
    }
    cout<<sum;
    return 0;
}
else{
sum=a[n];
for(long long i=n;i>=n-m+1;i--){
    sum=sum&a[i];
}
cout<<sum;
}
return 0;
}
