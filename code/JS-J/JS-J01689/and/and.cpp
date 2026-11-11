#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],maxn=0;
int n,m;
void dfs(int cnt,int x,int i){
	if(cnt==m){
		if(x>maxn)maxn=x;
		return ;
	}
	if(i>n)return ;
	//cout<<x<<' ';
	dfs(cnt+1,x&a[i],i+1);
	dfs(cnt,x,i+1);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn)maxn=a[i];
		}
		cout<<maxn;
		//cout<<endl;
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxn)maxn=a[i]&a[j];
				//cout<<maxn<<' ';
			}
		}
		cout<<maxn;
	}else if(m==3){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int t=a[i]&a[j];
					t=t&a[k];
					if(t>maxn)maxn=t;
					//cout<<maxn<<' ';
				}
			}
		}
		cout<<maxn;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		dfs(0,INT_MAX,1);
		cout<<maxn;
	}
	return 0;
}
//
