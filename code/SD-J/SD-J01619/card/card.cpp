#include<iostream>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],st[N];
int cnt;
bool f=1;
int vis[M];
int ans[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]) f=0;
	}
	if(m==2){
		int sum=0;
		if(a[n]==1){
			for(int i=1;i<n;i++){
				if(a[i]==2) sum++;
			}
			cout<<n<<" "<<sum;
		}
		else{
			for(int i=1;i<n;i++){
				if(a[i]==1) sum++;
			}
			cout<<sum<<" "<<n;
		}
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st[cnt]!=a[j]&&cnt){
					vis[st[cnt]]--;
					cnt--;
				}
				vis[st[cnt]]--;
				cnt--;
			}
			st[++cnt]=a[j];
			vis[a[j]]++;
		}
		for(int i=1;i<=cnt;i++){
			ans[st[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
