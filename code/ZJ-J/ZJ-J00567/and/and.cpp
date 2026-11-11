#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],cnt[35],qpow[35],ans;
string s[200005],g;
bool cmp(string a,string b){
	for(int i = 29;i >= 0;i--){
		if(cnt[i]>=m){
			if(a[i]=='1'&&b[i]=='0')return 1;
			if(a[i]=='0'&&b[i]=='1')return 0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		int num = 0;
		while(a[i]){
			if(a[i]%2)g="1",cnt[num]++;
			else g="0";
			s[i]=s[i]+g,a[i]/=2;
			num++;
		}
		while(s[i].size()<30)s[i]=s[i]+"0";
	}
	qpow[0]=1;
	for(int i = 1;i < 30;i++){
		qpow[i]=qpow[i-1]*2;
	}
	sort(s+1,s+1+n,cmp);
	for(int i = 29;i >= 0;i--){
		int f=1;
		for(int j = 1;j <= m;j++){
			f&=(s[j][i]-'0');
		}
		if(f)ans+=qpow[i];
	}
	cout<<ans;
	return 0;
}
