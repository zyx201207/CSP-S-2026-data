#include<bits/stdc++.h>
using namespace std;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		while(a!=0){
			char c=a%2+'0';
			s[i]=c+s[i];
			a=(a-a%2)/2;
		}
		reverse(s[i].begin(),s[i].end());
	}
	long long maxn=0;
	string sm;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			int q=0,c=1;
			string s1;
			for(int k=0;k<max(s[i].size(),s[j].size());k++){
				s1[k]=(s[i][k]-'0')&&(s[j][k]-'0')+'0';
			}
			for(int k=0;k<s1.size();k++){
				q+=(s1[k]-'0')*c;
				c*=2;
			}
			if(q>maxn){
				maxn=q;
				sm=s1;
			}
		}
	}
	m--;
	while(m--){
		for(int j=2;j<=n;j++){
			int q=0,c=1;
			string s1;
			for(int k=0;k<max(sm.size(),s[j].size());k++){
				s1[k]=(sm[k]-'0')&&(s[j][k]-'0')+'0';
			}
			for(int k=0;k<s1.size();k++){
				q+=(s1[k]-'0')*c;
				c*=2;
			}
			if(q>maxn){
				maxn=q;
				sm=s1;
			}
		}
	}
	cout<<maxn;
	return 0;
}
