#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],table[N],cnt[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flaga=true;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flaga=false;
		}
	}
	if(flaga==true){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cnt[a[j]]++;
			}
			for(int j=1;j<=m;j++){
				if(cnt[j]%2==1){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(n>5&&m<=2){
		if(a[n]==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2){
					cnt++;
				}
			}
			if(cnt%2==1){
				ans[2]++;
			}
			ans[1]++;
		}
		if(a[n]==2){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			if(cnt%2==1){
				ans[1]++;
			}
			ans[2]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=1;
		for(int j=1;j<=n;j++){
			table[i]=0;
		}
		for(int j=i;j<=n;j++){
			bool flag=false;
			for(int k=1;k<t;k++){
				if(table[k]==a[j]){
					flag=true;
					for(int l=k;l<t;l++){
						table[l]=0;
					}
					t=k;
					break;
				}
				if(flag==true){
					break;
				}
			}
			table[t]=a[j];
			t++;
		}
		for(int j=1;j<t;j++){
			ans[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
