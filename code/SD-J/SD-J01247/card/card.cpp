#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int cnt[3005];
int tot=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int T=1;T<=n;T++){
		tot=0;
		for(int i2=T;i2<=n;i2++){
			int id=tot+1;
			for(int i=1;i<=tot;i++){
				if(b[i]==a[i2])
				{
					id=i;
				}	
			}
			for(int i=id;i<=tot;i++){
				b[i]=0;
			}
			tot=id;
			b[tot]=a[i2];
		}
		for(int i=1;i<=n;i++){
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
	}
	return 0;
}

