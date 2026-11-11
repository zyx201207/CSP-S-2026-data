#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long ans=0;
string s;
pair<long long,string> a[N];
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		for(long long j=1;j<=a[i].first;j++){
			s=s+a[i].second;
		}
	}
	bool flag=0;
	for(long long i=0;i<s.size();i++){
		for(long long j=s.size()-1;j>0;j++){
			if(s[i]!=s[j])ans++,flag=1;
		}
	}
	if(flag==0)cout<<0;
	else cout<<ans;
	return 0;
}