#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=1e5+5;
int a[N];
bool vis[M];
int ans[M];
int ans1[M];
int cnt=0;
void work(int x){
	while(ans[cnt]!=x){
		vis[ans[cnt]]=0;
		cnt--;
	}
	return ;
}
void suan(){
	for(int i=1;i<=cnt;i++){
		ans1[ans[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n>=5e5){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				work(a[j]);
			}else{
				vis[a[j]]=1;
				cnt++;
				ans[cnt]=a[j];
			}
		}
		suan();
	}
	for(int i=1;i<=m;i++){
		cout<<ans1[i]<<' ';
	}
	return 0;
}
