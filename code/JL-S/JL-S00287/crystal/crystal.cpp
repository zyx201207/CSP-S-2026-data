#include<bits/stdc++.h>
using namespace std;
long long m,a[500001],l;
int t,i,k,n;
int cmp(int a,int b){
    return a<b;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
ios::sync_with_stdio(false);
for(i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n,cmp);
for(int j=n;j>=1;j--){
    t=1;
    l=m;
    for(i=j-1;i>=1;i--){
        l-=a[j]-a[i];
        if(l>=0)
            t++;
    }
    if(t>=k)
        k=t;
}
cout<<k;
return 0;
}

