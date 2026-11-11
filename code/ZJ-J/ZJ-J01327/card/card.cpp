#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],r[500005],f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		memset(f,0,sizeof(f));
		string s="";
		for(int j=i;j<=n;++j){
			if(s.find(a[j])<=n)s.erase(s.find(a[j]),s.size()-s.find(a[j]));
			s+=a[j];
		}
		for(int i=0;i<s.size();++i){
			if(f[s[i]])continue;
			f[s[i]]=0;
			r[s[i]]++;
		}
	}
	for(int i=1;i<=m;++i)cout<<r[i]<<' ';
} 
