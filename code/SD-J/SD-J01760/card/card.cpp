#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[500005];
long long book[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])
			flag=false;
	}
	if(flag==true){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		book[i]=a[i];
		for(int j=i+1;j<=n;j++){
			long long k=-1;
			for(int s=j-1;s>=i;s--){
				if(book[s]==a[j]){
					k=s;
					break;
				}
			}
			if(k!=-1){
				for(int s=j-1;s>=k;s--){
					book[s]=0;
				}
			}
			book[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(book[j]!=0){
				ans[book[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

