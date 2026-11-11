#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[500010],da[300010];
int xb[300010],xbz[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int sz=0;
	for(int i=1;i<=n;i++){
		sz++;
		if(xbz[s[i]]==0){
			xbz[s[i]]=1;
			xb[s[i]]=sz;
		}
		else{
			sz=xb[s[i]];
			xbz[s[i]]=0;
			for(int j=1;j<=sz;j++){
				if(xb[j]>xb[s[i]]){
					xbz[j]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(xbz[j]==1){
				da[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<i<<" "<<m<<"\n";
		cout<<da[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/