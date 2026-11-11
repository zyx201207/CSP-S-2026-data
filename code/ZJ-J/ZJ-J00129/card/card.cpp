#include<bits/stdc++.h>
using namespace std;

long long n,m,f[500005],g[500005];
int main(){
	freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		int len,k[500005];
		vector<long long> l;
		for(int j=i;j<=n+1;j++){
			l.push_back(f[j]);
			len=l.size();
			for(int q=0;q<len-1;q++){
				if(l[q]==f[j]){
					l.erase(l.begin()+q+1,l.begin()+len);
					len=l.size();
				}
			}
		}
		for(int i=1;i<=m;i++){
			k[i]=0;
		}
		for(int j=0;j<len-1;j++){
			k[l[j]]=1;
		}
		for(int j=1;j<=m;j++){
			g[j]+=k[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<' ';
	}
	return 0;
}
