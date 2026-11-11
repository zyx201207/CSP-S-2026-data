#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans; //l:◊Û÷∏’Î r:”“÷∏’Î 
vector<char> s;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i]){
			s[i]=s[s.size()-i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

