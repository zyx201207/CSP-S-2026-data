#include<bits/stdc++.h>
using namespace std;
int a[200100];
int n,m,ans=0;
int b[200100];
void dfs(int x){
	if(x==n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				cnt++;
				if(sum==0){
					sum+=a[i];
				}else{
					sum&=a[i];
				}
			}
		}
		if(cnt==m){
			ans=max(ans,sum);
		}
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
