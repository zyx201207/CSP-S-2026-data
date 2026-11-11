#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],e[500005],e1[500005],f[300005],s[500005],t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++) s[i]=i;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(f[c[i]]!=0) {
//			cout<<c[i]<<' '<<i<<' '<<f[c[i]]<<'\n';
			e[f[c[i]]]=i;
			e1[i]=f[c[i]];
		}
		f[c[i]]=i;
	}for(int i=1;i<=a;i++){
		if(e1[i]) t-=s[e1[i]],s[e1[i]]=0;
		s[i]-=t;
		if(e[i]) t+=s[i];
	}
	for(int i=1;i<=a;i++) f[c[i]]=s[i];
	for(int i=1;i<=b;i++) cout<<f[i]<<' ';
	return 0; 
}
