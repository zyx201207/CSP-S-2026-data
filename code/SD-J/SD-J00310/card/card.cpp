#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=n;
	while(t--){
		for(int i=1;i<=t;i++) b[i]=a[i];
		for(int i=1;i<=t;i++){
			for(int j=1;j<i;j++){
				if(b[i]==b[j]){
					for(int k=j;k<i;k++){
						b[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=t;i++){
			if(b[i]!=0) cnt[b[i]]++;
		}
		for(int i=1;i<=t;i++){
			b[i-1]=b[i];
		}
	}
	cnt[a[n]]=n; 
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
