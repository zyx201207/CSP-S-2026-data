//SN-J00564
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],cnt[200010];//cnt[i]:第i个数有几位是1 
int ans=0;
bool cmp(const int &x,const int &y){
	return x>y;
}
void dfs(int limit,int tot,int sum){
	if(tot==m){
		ans=max(ans,sum);
		return ;
	} 
	if(limit==n+1) return ;
	dfs(limit+1,tot+1,sum&a[limit]);//选 
	dfs(limit+1,tot,sum);//不选 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//#6 m=1
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	//#7 n=m
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		printf("%d",ans);
		return 0;
	}
	//#8~10 m=2
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}
	//特殊性质A 
	bool flag=1;
	for(int i=1;i<=n;i++){
		bool flagg=0;
		for(int j=1;j<=30;j++){
			if(a[i]==(1<<j)-1){
				flagg=1;
				break;
			}
		}
		if(flagg==0){
			flag=0;
			break;
		}
	}
	if(flag){
		sort(a+1,a+n+1,cmp);
		printf("%d",a[m]);
		return 0;
	}
	//#1~5 n<=20 
	dfs(1,0,(1<<30)-1);
	printf("%d",ans);
	return 0;
}
