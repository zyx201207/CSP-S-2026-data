#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010];
string s,x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			x="";
			for(int k=0;k<s.size();k++){
				if(s[k]==char(a[j]+'0'))break;
				x=x+s[k];
			}
			s=x+char(a[j]+'0');
		}
		for(int j=0;j<s.size();j++)b[s[j]-'0']++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}