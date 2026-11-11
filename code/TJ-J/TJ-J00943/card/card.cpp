#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)t[i]=a[i];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)a[i]=t[i];
		for(int i=k;i<=n;i++){
			int f=0;
			for(int j=k;j<i;j++){
				if(a[j]==a[i]){
					f=j;
					break;
				}
			}
			if(f){
				for(int j=f;j<i;j++){
					a[j]=0;
				}
			}
		}
		for(int i=k;i<=n;i++){
			if(a[i])cnt[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
