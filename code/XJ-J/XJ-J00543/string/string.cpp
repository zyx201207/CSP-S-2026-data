#include<bits/stdc++.h>
using namespace std;
struct Item{
	long long t;
	char c;	
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	vector<Item> a(n);
	string ans;
	for(int i=0;i<n;++i){
		cin>>a[i].t>>a[i].c;
		for(int j=0;j<a[i].t;++j)
			ans+=a[i].c;
	}
	string s=ans;
	reverse(s.begin(),s.end());
	long long cnt=0;
	for(int i=0;i<s.size();++i){
		if(ans[i]!=s[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}