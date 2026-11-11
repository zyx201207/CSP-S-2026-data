#include<bits/stdc++.h>
using namespace std;
int n,m,l,c[(int)5e5+10],d[(int)3e5+10],e[(int)5e5+10],g[(int)5e5+10];
bool b[(int)3e5+10],f;
vector<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a.resize(n+10);
	for(int i=n;i>0;i--){
		cin>>a[i];
		c[i]=d[a[i]];
		d[a[i]]=i;
	}
	l=n;
	while(l>=1){
		memset(e,0,sizeof(e));
		for(int i=l;i>0;i--){
			if(!(c[a[i]]>l||c[a[i]]==0)){
				e[i]++;
				g[c[a[i]]-1]++;
			} 
		}
		for(int i=1;i<=l;i++){
			f+=e[i];
			f-=g[i];
			b[i]=f%2;
		}
		l--;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
