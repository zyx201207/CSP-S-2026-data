#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int ans;
void dfs(int depth,int num,int sum){
	if(depth==n+1){
		if(num==m){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(depth+1,num+1,sum&a[depth]);
	dfs(depth+1,num,sum);
}
int lowbit(int x){
	return x&(-x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n<=20){
		dfs(1,0,INT_MAX);
		cout<<ans;
	}else{
		if(m==1){
			cout<<a[1];
		}else if(m==2){
			int num=a[1]&a[2];
			cout<<num;
		}else if(m==n){
			int num=a[1];
			for(int i=2;i<=n;i++){
				num&=a[i];
			}
			cout<<num;
		}else if(m==n-1){
			int num=a[1];
			for(int i=2;i<n;i++){
				num&=a[i];
			}
			cout<<num;
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				int num=0,hu=a[i];
				while(lowbit(hu)==1){
					hu=(hu>>1);
					num++;
				}
				long long num1=1;
				for(int j=1;j<=num;j++){
					num1*=2;
				}
				if(num1-1==a[i])cnt++;
			}	
			if(cnt==n){
				cout<<a[m];
			}else{
				int num=0;
				for(int i=1;i<=n;i++){
					if(a[i]==n-i)num++;
				}
				if(num==n){
					int sum=a[1];
					for(int i=2;i<=m;i++){
						sum&=a[i];
					}
					cout<<sum;
				}
			}
		}
	}
	return 0;
}
