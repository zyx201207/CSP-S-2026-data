#include<bits/stdc++.h>
using namespace std;
int a[500010],last[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int desk[500010];
		int p=1;
		for(int j=i;j<=n;j++){
			desk[p]=a[j];
			for(int x=1;x<p;x++){
				if(desk[x]==desk[p]){
					for(int iv=x;iv<=p;iv++){
						desk[iv]=0;
					}
					p=x;
					desk[p]=a[j];
				}
			}
			p++;
		}
		for(int i=1;i<p;i++){
			last[desk[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<last[i]<<" ";
	}
	return 0;
}

