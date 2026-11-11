#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int i=1;i<=num;i++) s+=c;
	}
	int tmp=s.size();
	long long ans=0;
	for(int i=0;i<tmp/2;i++){
		if(s[i]!=s[tmp-i-1]) ans++;
	}
	cout<<ans;
}
