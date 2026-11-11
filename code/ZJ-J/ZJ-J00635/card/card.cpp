#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[300005];
bool ok=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i-1]>a[i]) ok=1;
	}
	if(!ok){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) cnt[a[i]]++;
			else cnt[a[i]]=sum+1;
			sum++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
		cout<<'\n';
	}
	else{
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=i;j<=n;j++){
				int k;
				for(k=1;k<=sum;k++){
					if(a[j]==b[k]) break;
				}
				sum=k;
				b[sum]=a[j];
			}
			for(int j=1;j<=sum;j++) cnt[b[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
		cout<<'\n';
	}
	return 0;
}
