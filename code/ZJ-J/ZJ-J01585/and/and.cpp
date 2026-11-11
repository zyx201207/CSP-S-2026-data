#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int ans=0;
int a[N];
int p2[N];
int p[N][35];
bool vis[N];
bool cmp(int x,int y){
	return x>y;
}
void init(){
	p2[0]=1;
	for(int i=1;i<=30;i++){
		p2[i]=p2[i-1]*2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	init();
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if(a[i]>=p2[j]){
				a[i]-=p2[j];
				p[i][j]=1;
			}
		}
	}
	bool flag=true;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(p[i][j]==1 && cnt<m && flag){
				cnt++;
				vis[i]=1;
			}else if(!flag && vis[i] && p[i][j]==1){
				cnt++;
			}
		}
		if(cnt==m){
			flag=false;
			ans+=p2[j];
//			cout << p2[j] << endl;
		}
		if(flag){
			for(int i=1;i<=n;i++){
				vis[i]=0;
			}
//			cout << p2[j] << 'k' << endl;
		}
//		for(int i=1;i<=n;i++){
//			cout << vis[i] << " ";
//		}
//		cout << endl;
	}
	cout << ans << endl;
	return 0;
}

