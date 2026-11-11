#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],book[500005],na[500005],ca[500005],lst[300005],ans[300005],cnt[300005],flag=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=max(cnt[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		memset(book,0,sizeof(book));
		memset(lst,0,sizeof(lst));
		for(int i=k;i<=n;i++){
			book[i]=1;
		}
		for(int i=k;i<=n;i++){
			if(lst[a[i]]){
				for(int j=lst[a[i]];j<i;j++){
					book[j]=0;
					if(lst[a[j]]==j) lst[a[j]]=0;
				}
			}
			lst[a[i]]=i;
		}
		for(int i=k;i<=n;i++){
			if(book[i]) ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
