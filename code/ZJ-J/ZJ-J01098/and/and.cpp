#include <bits/stdc++.h>
using namespace std;
long long n,m,i,a[200010],ma;
long long f[100];
void dfs(long long x,long long s,long long sl){
	if(sl>m) return ;
	if(x>n){
		if(sl==m)ma=max(ma,s);
		return ;
	}
	dfs(x+1,(s&a[x]),sl+1);
	dfs(x+1,s,sl);
}
bool checkA(){
	long long i,j;
	for(i=1;i<=n;i++){
		bool fl=1;
		for(j=0;j<=30;j++)
			if(a[i]==pow(2,j)-1){
				fl=0;break;
			}else if(pow(2,j)-1>a[i]) break;
		if(fl==1) return 0;
	}
	return 1;
}
bool checkB(){
	long long fl,i,j;
	fl=1;
	for(j=0;j<=30;j++)
		if(pow(2,j)==n){fl=0;break;}
		else if(pow(2,j)>n) break;
	if(fl==1) return 0;
	for(i=1;i<=n;i++)
		if(a[i]!=i-1) return 0;
	return 1;
}
bool checkC(){
	for(i=1;i<=n;i++)
		if(a[i]>4) return 0;
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20){
		for(i=1;i<=n;i++) dfs(i+1,a[i],1);
		cout<<ma;
	}
	else if(m==1){
		for(i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma;
	}else if(m==2){
		for(i=1;i<=n;i++)
			for(long long j=i+1;j<n;j++)
				ma=max(ma,a[i]&a[j]);
		cout<<ma;
	}else if(m==n){
		ma=a[1];
		for(i=2;i<=n;i++) ma=ma&a[i];
		cout<<ma;
	}else if(checkA()){
		cout<<a[n-m+1];
	}
	else if(checkB()||checkC()){
		ma=a[n];
		for(i=n-1;i>=n-m+1;i--) ma=ma&a[i];
		cout<<ma;
	}
	else if(m==n-1){
		long long ans=a[1];
		for(i=1;i<=n;i++){
			ans=ans&a[i];
			for(long long j=0;j<=30;j++)
				if((1<<j)&a[i]) f[j]++;
		}
		for(i=1;i<=n;i++){
			long long ans1=ans;
			for(long long j=0;j<=30;j++)
				if((1<<j)&a[i]){
					f[j]--;
					if(f[j]==0) ans1=ans1-(1<<j);
				}
			ma=max(ma,ans1);
			for(long long j=0;j<=30;j++)
				if((1<<j)&a[i]){
					f[j]++;
				}
		}
		cout<<ma;
	}
	return 0;
}
/*
pts=85
ÆÀ²â»ú±£ÓÓÎÒ 
*/
