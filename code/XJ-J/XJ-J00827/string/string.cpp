#include<bits/stdc++.h>
using namespace std;
const long long P=2e5+5;
long long m[P],lon;
string s="0";
long long ans;
struct str{
	char ty;
	long long sum;
}a[P];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int t=1;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		lon+=b;
		for(int i=1;i<=b;i++){
			s+=c;
		}
	}
	for(int i=1;i<=(s.size()/2);i++){
		if(s[i]!=s[lon+1-i])ans++;
	}
	
	cout<<ans;
	return 0;
}
