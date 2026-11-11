#include<bits\stdc++.h>
using namespace std;
bool vis[1073741824];
int n;
int m;
long long a[200005];
long long maxxx=-1;
void dfs(long long d,long long ansss,long long djg){
	if(d==m){
		maxxx=max(maxxx,ansss);
		//cout<<maxxx<<endl;
		return ;
	}
	for(int i=djg+1;i<=n;i++){
		if(d==0){
			dfs(d+1,a[i],i);
		}
		else{
			if((long long)(ansss&a[i])>=maxxx){
				dfs(d+1,(long long)(ansss&a[i]),i);
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,0,0);
		cout<<maxxx;
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				maxxx=max(maxxx,a[i]);
			}
			cout<<maxxx;
		}
		else if(m==n){
			cin>>a[1];
			maxxx=a[1];
			for(int i=2;i<=n;i++){
				cin>>a[i];
				maxxx=(long long)(maxxx&a[i]);
			}
			cout<<maxxx;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			dfs(0,0,0);
			cout<<maxxx<<endl;
		}
	}
	else{
		if(m==n-1){
			long long maxx=-1;
			cin>>a[1];
			maxxx=a[1];
			bool flag=0;
			for(int i=2;i<=n;i++){
				cin>>a[i];
				maxxx=(long long)(maxxx&a[i]);
			}
			for(int i=1;i<=n;i++){
				long long qwe=maxxx^a[i];
				maxx=max(maxx,(long long)!qwe);
			}
			cout<<maxx;
		}
		else if(m==n){
			cin>>a[1];
			maxxx=a[1];
			for(int i=2;i<=n;i++){
				cin>>a[i];
				maxxx=(long long)(maxxx&a[i]);
			}
			cout<<maxxx;
		}
		else{
			bool flag1=0,flag2=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]!=i-1){
					flag1=1;
				}
			}
			if(flag2==0){
				sort(a+1,a+1+n);
				cout<<a[n-m+1];
			}
			else if(flag1==0){
				cout<<n-1;
			}
			else{
				dfs(0,0,0);
				cout<<maxxx;
			}
		}
	}
	return 0;
} 
