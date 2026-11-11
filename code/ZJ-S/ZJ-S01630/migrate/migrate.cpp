#include<bits/stdc++.h>
using namespace std;
long long a[1000010],c,T,n,d,maxs,sum,cnt[1000010],book[100010];
void dfs(int t){
	long long i=t+1,tt=t;
	while(i<=n){
		maxs=max(maxs,i);
		if(a[i]-a[t]<=d&&cnt[i]==0){
			cnt[i]=cnt[t]+1;
			book[i]=1;
		}
		else if(a[i]-a[t]<=d&&cnt[i]==cnt[t]+1){
			book[i]++;
			if(book[i]==2) sum++;
			else if(book[i]==3) sum--;
		}else if(a[i]-a[t]<=d&&cnt[i]>cnt[t]+1){
			if(book[i]==2) sum--;
			book[i]=1;
			cnt[i]=cnt[t]+1;
		}
		else if(a[i]-a[t]>d){
			for(int j=tt+1;j<i;j++)
				dfs(j);
			return ;
		}
		else tt++;
		i++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;sum=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			maxs=0;
			dfs(i);
			for(int k=i+1;k<=maxs;k++) cnt[k]=0,book[k]=0;
		}
		cout<<sum<<" ";
	}
	return 0;
}
/*
1
6 12
-10 -6 -2 2 6 10
*/