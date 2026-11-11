#include<bits/stdc++.h>
using namespace std;
long long maxa= -1;
long long fst(long long x){
	long long ans=1;
	for(long long i=1;i<=x;i++){
		ans*=2;
	}
	return ans;
}
string ttot(long long n){
	string s={};
	while(n!=0){
		s+=n%2+'0';
		n/2;
	} 
	return s;
}
long long anwy(string a,string b){
	string s={};
	long long ans=0;
	long long len1=min(a.size(),b.size());
	long long len2=max(a.size(),b.size());
	for(long long i=1;i<=len1;i++){
		if(a[i]==b[i]){
			s+='1';
		}else{
			s+='0';
		}
	}
	for(long long i=len1;i<=len2;i++)s+='0';
	for(long long i=len2;i>=1;i--){
		ans+=s[i]*fst(len2-i+1);
	}
}
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1)cout<<maxa;
	else{
		maxa= -1;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				maxa=max(maxa,anwy(ttot(a[i]),ttot(a[j])));
			}
		}
		cout<<maxa;
	}
	return 0;
}
