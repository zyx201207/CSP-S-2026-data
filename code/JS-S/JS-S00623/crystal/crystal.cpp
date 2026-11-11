#include<bits/stdc++.h>
using namespace std;
int n,a[500005],cnt,maxn,b[500005],k;
long long m;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
for(int j=1;j<=n;j++){
    b[j]=a[j];
}
long long t;
for(int i=1;i<n;i++){
    t=m;
    cnt=0;
    k=0;
    for(int j=i+1;j<=n;j++){
        if(t>=((b[j]-b[j-1])*(k+1))){
            cnt++;
            k++;
            //int p=j-1,s=k;
            //while(k){
            t-=(b[j]-b[j-1])*k;
            //}

            //b[j-1]+=b[j]-b[j-1];
        }
        else break;
    }
maxn=max(cnt+1,maxn);
}
cout<<maxn;
return 0;
}
