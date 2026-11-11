#include<bits/stdc++.h>
using namespace std;
//struct to{
//	long long lot;
//	char ch;
//};
//vector<to> v[200010];
long long high(long long x){
	if(x%2==0){
		return x/2;
	}else{
		return x/2+1;
	}
}
int main(){
	string s="";
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,ans=0;
	cin>>n;
//	for(int i=1;i<=n;i++){
//		long long a;
//		char c;
//		cin>>a>>c;
//		v[i].lot=a;
//		cnt+=a;
//	}
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		sum+=a;
		for(int i=1;i<=a;i++){
			s=s+b;
		}
	}
//	cout<<s;
	long long p=high(sum)-1;
	for(int i=p;i>=0;i--){
		if(s[i]!=s[s.size()-1-i]){
//			cout<<i<<" "<<s.size()-1-i<<"\n";
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
