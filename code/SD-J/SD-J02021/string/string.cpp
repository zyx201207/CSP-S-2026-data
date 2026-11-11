#include<bits/stdc++.h>
using namespace std;
char c[200005];
string s,s1;
long long n,a[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}cout<<ans/2ll;
	return 0;
}
