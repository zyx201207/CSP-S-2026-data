#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void dfs(int now,int x,int sum){
	if(now==n){
		if(x==m) ans=max(ans,sum);
		return ;
	}
	int y=sum&a[now];
	dfs(now+1,x,sum);
	if(x!=0) dfs(now+1,x+1,y);
	else dfs(now+1,x+1,a[now]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<ans;
	}else{
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,i);
			}
			cout<<ans;
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
		}else if(m=n-1){
			int pre[n+1],pre1[n+1];
			pre[1]=a[1],pre1[n]=a[n];
			for(int i=2;i<=n;i++){
				pre[i]=pre[i-1]&a[i];
			}
			for(int i=n-1;i>=2;i--){
				pre1[i]=pre1[i+1]&a[i];
				if(i==2){
					ans=max(ans,pre1[i]);
				}else{
					ans=max(ans,pre[i-2]&pre1[i]);
				}
			}
			ans=max(ans,pre[n-1]);
			cout<<ans;
		}else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int x=a[i]&a[j];
					ans=max(ans,x);
				}
			}
			cout<<ans;
		}else{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}