#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]==s[l-i-1]){
			continue;
		}else{
			s[l-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
