#include <bits/stdc++.h>
using namespace std;
long long n,m,z[500002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	for(int i=1;i<=m;i++){
		map <int,int> mp;
		int c[500002],v[2002],op=1,q=0;
		memset(c,0,sizeof(0));
		memset(v,0,sizeof(0));
		for(int o=1;o<=n;o++){
			for(int k=o;k<=n;k++){
				mp[z[k]]++;
				c[op]=z[k];
				op++;
				if(mp[z[k]]>=2){
					memset(v,0,sizeof(0));
					memset(c,0,sizeof(0));
					op=1;
				} 
			}
			for(int k=1;k<=op;k++){
				if(c[k]==i){
					q++;
					break;
				}
			}
			memset(c,0,sizeof(0));
		}
		cout<<q<<" ";
	}
	return 0;
}
