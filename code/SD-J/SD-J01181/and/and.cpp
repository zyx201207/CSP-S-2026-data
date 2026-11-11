#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
#define ll long long
ll ans;
int n,m;
ll a[N];
ll Count[N];
bool vis[N];
void DFS(int step,ll sum,int pre){
	vis[pre]=1;
//	cout<<sum<<" "<<step<<" "<<pre<<"\n";
	if(step==m){
		ans=max(ans,sum);;return ;}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			if(step==0)
				sum=a[i];
			DFS(step+1,sum&a[i],i);
			vis[i]=0;
		}
	return ;
}
bool checkTP2(int x){
	while(x>1){
		if(!(x&1))
			return 1;
		x>>=1;
	}
	return 0;
}
bool TP1(){
	for(int i=1;i<=n;i++)
		if(a[i]!=i-1)
			return 0;
	return 1;
}
bool TP2(){
	for(int i=1;i<=n;i++)
		if(checkTP2(a[i]))
			return 0;
	return 1;
}
bool TP3(){
	for(int i=1;i<=n;i++)
		if(a[i]>4)
			return 0;
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	if(TP3()){
		for(int i=1;i<=n;i++)
			Count[a[i]]++;
		if(Count[4]>=m) printf("4\n");
		else if(Count[3]>=m) printf("3\n");
		else if(Count[3]+Count[2]>=m) printf("2\n");
		else if(Count[3]+Count[1]>=m) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(TP1()){
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>n-m;i--)
			ans&=a[i];
		printf("%lld",ans);
		return 0;
	}
	if(TP2()){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	DFS(0,0,0);
	printf("%lld",ans);
	return 0;
}
