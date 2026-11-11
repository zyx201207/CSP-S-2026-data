#include<bits/stdc++.h>
using namespace std;
//#define unsigned long long long long
//#define unsigned long long unsigned long long
const unsigned long long maxn=2e5+13;
unsigned long long n,num=0;
string s;
bool pd;
//priority_queue<int> sb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=1;i<=n;i++){
		unsigned long long a;
		string b;
		cin>>a>>b;
		if(a>=1000000000||pd==1){
			num+=a;
			pd=1;
			continue;
		}
		for(unsigned long long j=1;j<=a;j++){
			s=s+b;
		}
	}
	if(pd==1){
		cout<<num/20;
	}
	unsigned long long ans=0;
	for(unsigned long long i=0;i<=s.size();i++){
		if(s[i]==s[s.size()-1-i]){
			continue;
		}
		ans++;
	}
	cout<<ans/2;
	return 0;
}
