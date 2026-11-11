#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long l=0,r=s.size()-1,ans=0;
	while(l<=r){
		if(s[r]!=s[l]){
			ans++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

