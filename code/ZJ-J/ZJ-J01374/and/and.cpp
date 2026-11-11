#include<bits/stdc++.h>
using namespace std;
int n,m,t1,t2,ans,t,a[200005];
vector<int> v[30];
void dfs(int mx){
	for(int i=0;i<=mx;i++) v[i].clear();
	for(int i=1;i<=n;i++){
		t2=t1;
		for(int j=29;j>=0;j--){
			if(a[i]>=t2){
				a[i]-=t2;
				v[j].push_back(a[i]);
			}
			if(a[i]==0) break;
			t2/=2;
		}
	}
	bool flag=0;
	for(int i=mx;i>=0;i--){
		if(v[i].size()>=m){
			flag=1;
			t=i;
			ans+=1<<i;
			n=0;
			for(int j=0;j<v[i].size();j++){
				a[++n]=v[i][j];
			}
			break;
		}
	}
	if(flag) {
		dfs(t-1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	t1=pow(2,29);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(29);
	cout<<ans;
	return 0;
} 
