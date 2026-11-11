#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int d[300005];//上次出现的位置 
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>=5001){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			d[a[i]]++; 
		}
		long long sum=0;
		for(int i=1;i<=m;i++){
			sum+=d[i];
			cout<<sum<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!d[a[j]])d[a[j]]=j;
			else{
				for(int k=d[a[j]];k<j;k++){
					d[a[k]]=0;
				}
				d[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(d[j]){
				ans[j]++;
				d[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}

