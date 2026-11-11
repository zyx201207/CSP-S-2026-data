#include<bits/stdc++.h>
using namespace std;
string s,s2,s3;
int a[100009];
int and1(int a,int b){
	for(int i=1;a!=1;i++){
		s[i]=a%2;
		a/=2;
	}
	for(int i=1;b!=1;i++){
		s2[i]=b%2;
		b/=2;
	}
	long long l=s.size();
	long long l2=s2.size();
	long long se=max(l,l2)-min(l,l2),sp=0,kb=0;
	for(int i=0;i<=max(l,l2);i++){
		s3[i]=s[i]&&s2[i];
	}
	for(int i=0;i<=max(l,l2);i++){
		sp+=(s3[i]-'0')*pow(2,i);
	}
	return sp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,k=0,sm=0,t=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;t==k-1;i++,t++){
		ans=and1(ans,a[i]);
	}
	cout<<ans;
	return 0; 
}
