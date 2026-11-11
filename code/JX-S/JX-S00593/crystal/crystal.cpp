#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],b[N],c[N],maxn,t[N],lol,tgc;
unsigned long long m,tot,sum;
void solvea(){
	for(int i=1;i<=n;i++){
		unsigned long long j=i*(i+1);
		if(m<=j/2)cout<<i;
	}
	return;
}
void solveb(int h){
	for(int i=1;i<=n;i++){
		unsigned long long j=(i-1)/h*(i+1);
		if(m<=j/2)cout<<i;
	}
	return;
}
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i)lol++;
        if(i>=2&&(a[i]-a[i-1]==(a[2]-a[1])))tgc++;
   }
   sort(a+1,a+n+1);
   if(lol==n&&m>=1e9+5){
	   solvea();
	   return 0;
   }
   if(tgc==n&&m>=1e9+5){
	   solveb(a[2]-a[1]);
	   return 0;
   }
   for(int i=1;i<=n;i++){
       b[i]=a[n]-a[i];
       tot+=b[i];
       c[i]=a[i]-a[i-1];
       t[a[i]]++;
       maxn=max(maxn,t[a[i]]);
   }
   c[1]=0;
   if(tot<=m){
        cout<<n;
        return 0;
   }
   for(int i=2;i<=n;i++){
	   sum+=c[i]*(i-1);
	   if(sum>m){
		   cout<<max(maxn,i-1);
		   break;
	   }
   }
   return 0;
}
