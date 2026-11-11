#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],ans=0,mid,maxn=INT_MIN,gcd=INT_MIN;
string s1="",s2="",s3="",c;

void gcdhs(){
	for(long long j=maxn;j>=1;j++){
		for(long long k=0;k<n;k++){
			if(a[k]%j!=0) return ;
		}
		gcd=max(gcd,j);
	}
	return ;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		maxn=max(a[i],maxn);
	}
	gcdhs();
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i]/gcd;j++){
			s3=s3+c[i];
		} 
	}
	mid=s3.size()/2;
	

	for(long long i=s3.size();i>mid;i--) s2=s2+s3[i];
	for(long long i=0;i<mid;i++){
		if(s3[i]!=s2[i+1]){
		ans++;
	}
	} 
	cout<<ans*gcd;

	return 0;
}