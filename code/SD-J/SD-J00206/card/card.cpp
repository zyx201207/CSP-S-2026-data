#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],t[300010],ton[300010],map1[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int o=i+1;o<=n;o++) b[a[o]]++;
		for(int o=1;o<=m;o++) ton[o]=0;
		for(int o=n;o>i;o--){
			if(ton[a[o]]>=1){
				b[a[o]]--,b[a[o+1]]--,o--;
			}
			ton[a[o]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
