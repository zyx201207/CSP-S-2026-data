#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long l[N];
long long sl;
long long minl=1e9+5;
long long g(){
	long long ans=1;
	for(long long k=minl;k>=2;k--){
		bool f=1;
		for(long long i=1;i<=n;i++){
			if(l[i]%k!=0){
				f=0;
				break;
			}
		}
		if(f){
			return k;
		}
	}
	return 1;
}
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin.tie(0);
	cout.tie(0);
	string s;
	char c[N];
	cin>>n;
	s.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>l[i];
		minl=min(minl,l[i]);
		cin>>c[i];
		
	}
	long long k=g();
	for(long long i=1;i<=n;i++){
		l[i]/=k;
		long long a=l[i];
		while(a--){
			s.push_back(c[i]);
		}
	}
	long long len=s.size()-1;
	string b=s;
	for(long long i=1;i<=len>>1;i++){
		b[i]=s[len-i+1];
	}
	long long f=0;
	for(long long i=1;i<=len>>1;i++){
		if(b[i]!=s[i]){
			f++;
		}
	}
	cout<<f*k;
	return 0;
}
