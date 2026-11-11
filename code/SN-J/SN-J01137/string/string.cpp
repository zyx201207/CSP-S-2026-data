#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string s = "";
	long long l=0;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		while(a--)s+=c;
	}
	long long ans=0;
	for(long long i=0;i<l/2;i++){
		if(s[i] != s[l-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
