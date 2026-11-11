#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[200005];
int n,m,sss=0;
bool cmp1(long long a,long long b){
	return a > b;
}
void dfs(int x,int cnt,int y){
	if(x>n){
		return ;
	}
	if(cnt==m){
		sss=max(sss,y);
		return ;
	}
	long long w=y & a[x];
	dfs(x+1,cnt+1,w);
	dfs(x+1,cnt,y);	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0,ss=0;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=4){
			cnt++;
		}
		if(a[i]==4){
			ss++;
		}
		maxx=max(maxx,a[i]);
	}
	if(cnt==n){
		if(ss>=m){
			printf("4");
			return 0;
		}
		sort(a+1,a+n+1);
		int sum=a[n-ss];
		for(int i=n-ss-1;i>=n-m;i--){
			sum =sum & a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==1){
		cout<<maxx;
	}
	else if(m==2){
		long long maxxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				maxxx=max(maxxx,a[i] & a[j]);
			}
		}
		cout<<maxxx;
		
	}
	else if(n==m){
		long long sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(n<=20){
		sort(a+1,a+n+1,cmp1);
		dfs(1,0,maxx);
		printf("%d",sss);
	} 
	else{
		long long sum=a[n];
		for(int i=n-1;i>=n-m;i--){
			sum=sum & a[i];
		}
		cout<<sum;
	}
	return 0;
} 
