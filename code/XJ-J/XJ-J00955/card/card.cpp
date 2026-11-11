#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010],tans[300010],k[500010],w;
string s;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		w=1;
		for(int o=1;o<=m;o++){
			t[o]=0;
			k[o]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]>=1){
				for(int o=1;o<=w;o++){
					if(k[o]==a[j]){
						for(int v=o;v<=w;v++){
							t[k[v]]=0;
						}
						w=o;
						break;
					}
				}
			}
			t[a[j]]++;
			k[w]=a[j];
			w++;
		}
		for(int j=1;j<=m;j++){
			if(t[j]>0){
				tans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tans[i]<<' ';
	}
	return 0;
}
