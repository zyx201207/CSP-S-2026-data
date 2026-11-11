#include <bits/stdc++.h>
using namespace std;
int n;
long long sum,a[100005],l,ans,d[30];
string s;
char c[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s='0';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
		l+=a[i];
	}
	for(int i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}//Trick||Treat!
