#include<bits/stdc++.h>
using namespace std;
int n,k,c[100],a[200010],ans;
int dfs(int x){
	if(x>20){
		int cnt=-1,sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]){
				if(cnt==-1)cnt=a[i];
				else cnt=cnt&a[i];
				sum++;
			}
		}
		if(sum==k)ans=max(ans,cnt);
		return 0;
	}
	c[x]=0,dfs(x+1);
	c[x]=1,dfs(x+1);
	c[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	if(n==k){
		int ans=a[1];
		for(int i=1;i<=n;i++)ans=ans&a[i];
		printf("%d",ans);
		return 0;
	}
	if(k==2){
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ans=max(ans,a[i]&a[j]);
		printf("%d",ans);
		return 0;
	}
//				if(k==n-1){
//					int ans=0;
//					for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ans=max(ans,a[i]&a[j]);
//					printf("%d",ans);
//				}
	int ta=1,pow=1,ok;
	for(int i=1;i<=n;i++){
		pow=1,ok=1;
		for(int j=1;j<=n;j++){
			pow*=2;
			if(ok==0&&a[i]&pow!=0)ta=0;
			if(a[i]&pow==0)ok=0;
		}
	}
	if(ta==1){
		int ans=a[1];
		sort(a+1,a+n+1);
		for(int i=n;i>=n-k+1;i--)
			ans=ans&a[i];
		printf("%d",ans);
		return 0;
	}
	int tc=1;
	for(int i=1;i<=n;i++)
		if(a[i]>4)tc=0;
	if(tc){
		int cnt0,cnt1,cnt2,cnt3,cnt4;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt0++;
			if(a[i]==1)cnt1++;
			if(a[i]==2)cnt2++;
			if(a[i]==3)cnt3++;
			if(a[i]==4)cnt4++;
		}
		if(cnt4>=k)printf("4");
		else if(cnt3>=k)printf("3");
		else if(cnt3+cnt2>=k)printf("2");
		else if(cnt3+cnt1>=k)printf("1");
		else printf("0");
		return 0;
	}
	printf("0");
	return 0;
}
/*
5 3
31 3 1 15 7
*/
/*
4 2
3 15 12 12
*/
/*
4 1
3 15 12 12
*/
