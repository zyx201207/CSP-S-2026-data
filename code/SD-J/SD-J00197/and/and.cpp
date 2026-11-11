#include<bits/stdc++.h>
using namespace std;
int a[2000005],maxa,a1[2005];int n,m,ans;
void dfs(int u){
	if(u==n){
		int ans1=0,sum=0;
		for(int i=0;i<n;i++){
			if(a1[i]==1) sum++;
		} 
		if(sum!=m)return;
		else {
			ans1=0;
			for(int i=0;i<n;i++){
				if(a1[i]==1){
					if(ans1==0) ans1=a[i];
					else ans1=(ans1 & a[i]);
					//cout<<"ans1: "<<ans1<<"max: "<<maxa<<endl;
					//cout<<a[i]<<" ";
				}
			}
			maxa=max(maxa,ans1);
			//cout<<endl;
		}
		
//		for(int i=0;i<n;i++){
//			if(a1[i]==1) cout<<a[i+1]<<" ";
//			else cout<<0<<" ";
//		}
//		cout<<'\n';
		
		return;
	}
	a1[u]=1;
	dfs(u+1);
	a1[u]=0;
	dfs(u+1);
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		int max2=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(0);
		cout<<maxa;
	}

	else {
		if(m==1) cout<<a[n-1];
		else if(m==2){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j) continue;
					max2=max(max2,(a[i] & a[j]));
				}
			}
		}
		cout<<max2;
	}
}
