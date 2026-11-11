#include<bits/stdc++.h>
using namespace std;
int a[200005],a1[35],b1[35];
int n,m;
string z(int x){
	string s1;
	while(x){
		if(x%2==0) s1='0'+s1;
		else s1='1'+s1;
		x/=2;
	}
	return s1;
}
int q(int a,int b){
	int sum=0,o=1;
	string s1=z(a),s2=z(b);
	int l1=s1.size(),l2=s2.size();
	for(int i=1;i<=l1;i++) a1[i]=s1[l1-i]-'0';
	for(int i=1;i<=l2;i++) b1[i]=s2[l2-i]-'0';
	for(int i=1;i<=min(l1,l2);i++){
		if(a1[i]==b1[i]&&a1[i]==1){
			sum+=o;
		}
		o*=2;
	}
	return sum;
}
bool cmp(int a,int b){
	return a>b;
}
bool k(int x){
	x++;
	while(x%2==0){
		x/=2;
	}
	if(x==1) return 0;
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x=1,big=INT_MIN;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k(a[i])) x=0;
		big=max(big,a[i]);
	}
	if(m==1){
		cout<<big;
		return 0;
	}
	if(m==2){
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			int sum=a[i];
			int sum1=q(sum,a[i+1]);
			for(int j=i;j<=n;j++){
				sum1=max(sum1,q(sum,a[i+1]));  
			}
			maxx=max(sum1,maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=q(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if(x==1){
		cout<<a[m];
		return 0;
	}
	int sum=a[1];
	for(int i=1;i<=m;i++) cout<<a[i]<<' ';
	for(int i=2;i<=m;i++){
		sum=q(sum,a[i]);
	}
	cout<<sum;
	return 0;
}