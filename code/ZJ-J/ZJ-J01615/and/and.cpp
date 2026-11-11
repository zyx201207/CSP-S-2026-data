#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[200005],ans=0,vis[200005],t[200005],cnt[10];
int f4=1;
void dfs(int x){
	if(x==m+1){
		unsigned long long sum=t[1];
		for(int i=1;i<=m;i++){
			sum=sum&t[i];
		}
		ans=max(sum,ans);
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				t[x]=a[i];
				dfs(x+1);
				t[x]=0;
				vis[i]=0;
			}
		}
	}
}
bool cmp(unsigned long long q1,unsigned long long q2){
	return q1>q2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4)f4=0;
		else cnt[a[i]]++;
	}	
	if(n<=30){
		dfs(1);
		cout<<ans;
	}
	else if(m==1){
		unsigned long long mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==2){
		unsigned long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else if(m==n){
		unsigned long long sum=a[1];
		for(int i=1;i<=n;i++)sum=sum&a[i];
		cout<<sum;
	}else if(f4==1){
		if(cnt[4]>=m)cout<<4;
		else if(cnt[3]>=m)cout<<3;
		else if((cnt[2]+cnt[3])>=m)cout<<2;
		else if((cnt[1]+cnt[3])>=m)cout<<1;
		else cout<<0;
	}else{
		sort(a+1,a+n+1,cmp);
		unsigned long long sum=a[1];
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}cout<<sum;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
