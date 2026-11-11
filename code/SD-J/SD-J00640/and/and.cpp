#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans,l;
string s[N],c[N];
bool cmp(string a,string b){
	int l1=a.size(),l2=b.size();
	if(l1>l2) return a>b;
	if(l1<l2) return b>a;
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]!=0){
			c[i]+=(a[i]%2+'0');
			a[i]/=2;
		}
		int k=c[i].size();
		l=max(l,k);
	}
	for(int i=1;i<=n;i++){
		if(c[i].size()<l){
			int k=l-c[i].size(); 
			for(int j=1;j<=k;j++){
				c[i]+="0";
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=c[i].size()-1;j>=0;j--){
			s[i]+=c[i][j];
		}
	}
	sort(s+1,s+n+1,cmp);
	c[1]=s[1];
	for(int i=2;i<=m;i++){
		for(int j=0;j<s[1].size();j++){
			if(c[1][j]=='1'&&s[i][j]=='1') c[1][j]='1';
			else c[1][j]='0';
		}
	}
	s[1]="";
	for(int i=c[1].size()-1;i>=0;i--){
		s[1]+=c[1][i];
	}
	l=2; 
	ans=(s[1][0]-'0');
	for(int i=1;i<s[1].size();i++){
		ans+=(s[1][i]-'0')*l;
		l*=2;
	}
	cout<<ans;
	return 0;
}
