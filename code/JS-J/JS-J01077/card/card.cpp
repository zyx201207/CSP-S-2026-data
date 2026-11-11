#include<bits/stdc++.h>
using namespace std;
int flag,n,m,a[500003],s[300003],d[500003],ans[500003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])flag=1;
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int i=n;i>=1;i--){
			if(!s[a[i]]){
				s[a[i]]=i;
			}
			else{
				d[i]=s[a[i]];
			}
		}
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			for(int j=i;j<=n;){
				if(!d[j]){
					j++;
					ans[a[j]]++;
				}
				else{
					j=d[j];
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
