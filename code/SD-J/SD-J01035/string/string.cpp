#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
string s,s1;
int sum;
map<int,int> m;
signed main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1,j=n;i<=n;i++,j--){
		cin>>a[i];
		cin>>c[i];
//		s+=c[i];
//		cc[j]=c[i];
		m[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		while(a[i]--) s+=c[i];
	}
	for (int i=s.size()-1;i>=0;i--) s1+=s[i];
	for (int i=0;i<s.size();i++) {
		if (s[i]!=s1[i]) sum++;
	}
//	cout<<s<<' '<<s1;
	cout<<sum/2;
//	for (int i=1;i<=n;i++){
//		cout<<cc[i];
//	}
	return 0;
}
/*
aabbc cbbaa
abc 221
cba 122
*/
