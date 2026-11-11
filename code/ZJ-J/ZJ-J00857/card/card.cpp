#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],lst[510000],cnt[510000],nxt[510000];
int k,t[510000];
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			lst[j]=0;
		}
		k=0;
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==0){
				t[++k]=a[j];
				lst[a[j]]=k;
			}else{
				for(int l=k;l>lst[a[j]];l--){
					lst[t[l]]=0;
				}
				k=lst[a[j]];
			}
		}
		for(int j=1;j<=k;j++){
			cnt[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return ;
}
void solve2(){
	int flagA=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]<a[i-1]){
			flagA=0;
		}
	}
	if(flagA){
		int lst=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]!=lst){
				cnt[lst]=i-1;
				lst=a[i];
			}
		}
		cnt[lst]=n;
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<"\n";
		}
		return ;
	}
	for(int i=n;i>=1;i--){
		if(i==n||a[i+1]!=a[i]){
			nxt[i]=i;
		}else{
			nxt[i]=nxt[i+1];
		}
	}
	for(int i=1;i<=n;i++){
//		if(a[i]==a[i-1]){
//			for(int j=1;j<=k;j++){
//				cnt[t[j]]++;
//			}
//			continue;
//		}
		for(int j=1;j<=m;j++){
			lst[j]=0;
		}
		k=0;
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==0){
				t[++k]=a[j];
				lst[a[j]]=k;
			}else{
				for(int l=k;l>lst[a[j]];l--){
					lst[t[l]]=0;
				}
				k=lst[a[j]];
			}
			j=nxt[j];
		}
		for(int j=1;j<=k;j++){
			cnt[t[j]]+=(nxt[i]-i+1);
		}
		i=nxt[i];
	}
	for(int i=1;i<=m;i++){
//		printf("%d ",cnt[i]);
		cout<<cnt[i]<<" ";
	}
	return ;
}
void solve3(){
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n]){
			cnt[a[i]]++;
		}
	}
	cnt[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		solve1();
		return 0;
	}else if(m<=2){
		solve3();
		return 0;
	}else{
		solve2();
		return 0;
	}
	return 0;
}
