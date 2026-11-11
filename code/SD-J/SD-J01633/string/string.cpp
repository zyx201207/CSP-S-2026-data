#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> s;
	long long sum=0;
	s.push_back(11111);
	for(int i=1;i<=n;i++){
		int x;
		char ss;
		cin>>x>>ss;
		for(int i=1;i<=x;i++){
			s.push_back(ss);
		}
		sum+=x;
	}
	int ans=0;
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
