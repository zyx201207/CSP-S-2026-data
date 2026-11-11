#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
string t;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0;
	while(l<n){
		string s="";
		l++;
		for(int i=l;i<=n;i++){
			if(s.find(char(a[i]+'0'))<s.size()){
				t=s.substr(0,s.find(char(a[i]+'0'))+1);
				s=t;
			}else{
				s=s+char(a[i]+'0');
			}
		}
		int l=s.size();
		for(int i=0;i<l;i++){
			c[int(s[i]-'0')]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(c[i]!=0){
			cout<<c[i]<<' ';
		}
	}
	return 0;
}
