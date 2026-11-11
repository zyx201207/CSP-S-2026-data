#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
vector<int> v;
void dfs(int pos,int idx){
	if(pos==m+1){
		int res=a[v[0]];
		for(int it:v)res&=a[it];
		ans=max(ans,res);
	}
	for(int i=idx+1;i<=n;i++){
		v.push_back(i);
		dfs(pos+1,i);
		v.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0);
		cout<<ans;
	}
	else if(n<=2000){
		if(m==1)cout<<a[n];
		else if(m==n){
			for(int i=1;i<=n;i++)ans&=a[i];
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}else{
		cout<<a[m];
	}
	return 0;
} 
