#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
int box[200005];
int a[200005]; 	 
void dfs(int x,int w){//选到第几个了 选了几个  
	if(w==k){
		int sum=box[1];
		for(int i=2;i<=k;i++){
			sum&=box[i];
		}
		for(int i=1;i<=k;i++){
//			cout<<box[i]<<" ";
		}
//		cout<<sum;
//		cout<<endl;		
		if(sum>ans){
			ans=sum;
		}
		return;
	}
	if(x>n){
		return;
	}
		box[w+1]=a[x];
		dfs(x+1,w+1);
		dfs(x+1,w);

		
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
	
	dfs(1,0);
	cout<<ans;
	return 0;
}else{
	if(k==n-1){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(maxx<ans&a[i]){
				maxx=ans&a[i];
			}
		}
		cout<<maxx;
		return 0;
	}else{
		cout<<0;
	}
//	cout<<0;
}
	return 0;
}
