#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],ans[500010],cha[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])
			f=0;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=i;j<=n;j++){
				for(int k=1;k<=cnt;k++){
					if(a[j]==b[k])
						cnt=k-1;
				}
				b[++cnt]=a[j];
			}
			for(int j=1;j<=cnt;j++)
				ans[b[j]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++)
			cha[a[i]]++;
		for(int i=1;i<=n;i++){
			cha[i]+=cha[i-1];
			cout<<cha[i]<<' ';
		}
	}
	return 0;
}
