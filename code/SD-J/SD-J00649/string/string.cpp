#include<bits/stdc++.h>
using namespace std;
long long L,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		L+=a; 
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	} 
	long long l=L/2;
	for(long long i=0;i<l;i++){
		if(s[i]!=s[L-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

