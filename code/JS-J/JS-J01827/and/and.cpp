#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005]; 
long long awy(long long a,long long b){
	if (a==b) return a;
	if (a==0||b==0) return 0;
	string aaa="";
	string bb="";
	while (a){
		int x=a%2;
		if (x==1) aaa=aaa+"1";
		else aaa=aaa+"0";
		a/=2;
	}
	while (b){
		int x=b%2;
		if (x==1) bb=bb+"1";
		else bb=bb+"0";
		b/=2;
	}
	string ans;
	while (aaa.size()<bb.size()) aaa="0"+aaa;
	while (bb.size()<aaa.size()) bb="0"+bb;
	int lenb=bb.size();
	string aa="";
	for (int i=lenb-1;i>=0;i--){
		aa+=aaa[i];
	}
	bool ifff=false;
	for (int i=0;i<lenb;i++){
		if (aa[i]=='0'||bb[i]=='0'){
			ans+="0";
		} else {
			ans+="1";
			ifff=true;
		}
		 
	}
	long long anss=0;
	if (ifff==false){
		return anss;
	} 
	for (int i=lenb-1;i>=0;i--){
		if (ans[i]=='0') continue;
		int ii=lenb-i-1;
		int two=1;
		while (ii--) two*=2;
		anss+=two;
	}
	return anss;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (m==1){
		cout<<a[n]<<"\n";
		return 0;
	}
	if (m==n){
		for (int i=2;i<=n;i++){
			a[i]=awy(a[i],a[i-1]);
		}
		cout<<a[n]<<"\n";
		return 0;
	}
	if (m==2){
		long long ans=LLONG_MIN;
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,awy(a[i],a[j]));
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	if (m==n-1){
		long long anss=LLONG_MIN;
		for (int i=1;i<=n;i++){
			long long ans=INT_MIN;
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				ans=awy(ans,a[j]);
			}
			anss=max(anss,ans);
		}
		cout<<anss<<"\n";
		return 0;
	}
	long long dp[200005]={0};
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			dp[i]=max(dp[i],awy(dp[i-1],a[j]));
		}
	}
	cout<<dp[m]<<"\n";
	return 0;
}
