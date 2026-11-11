#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int cishu[30000005];
int user[30000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		user[a[i]]++;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(user[i]==1) cnt++;
	}
	if(cnt==n){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cishu[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cishu[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int biaoji=i;
		for(int j=1;j<=m;j++){
			user[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(user[a[j]]){
				for(int k=biaoji;k<=j;k++){
					user[a[k]]=0;
				}
				biaoji=j;
				user[a[j]]==1;
			}
			else{
				user[a[j]]=1;
			}
		}
		for(int j=i;j<=n;j++){
			if(user[a[j]]) cishu[a[j]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<cishu[i]<<" ";
	}
	return 0;
} 
