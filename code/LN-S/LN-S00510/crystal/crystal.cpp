#include<bits/stdc++.h>
using namespace std;
#define QwQ return 0;
int n;
long long m;
long long b[500002];
bool cmp(int a,int b){
return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);
cin>>n>>m;
long long a[n+1];
for(long long i=0;i<n;i++)
{
    cin>>a[i];
    b[a[i]]++;
}
sort(a,a+n,cmp);
long long k=0;
for(long long i=0;i<n;i++){
    if(a[i]==a[i+1])continue;
    long long cnt=0,mm=m;
    for(long long j=i;j>=0;j--){
        if(a[i]-a[j]<=mm)
            cnt++,mm=mm-a[i]+a[j];
    }
    k=max(k,cnt);
}
cout<<k;
QwQ;
}
