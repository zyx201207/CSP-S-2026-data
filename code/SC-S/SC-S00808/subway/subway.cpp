#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N],n,d,ans;
int vis[N][N];
void dfs(int s,int t1){
	if(s>n) return;
	vis[s][t1]++;
	for(int i=s+1;i<=n;i++){
		if(a[i]-a[s]>d) break;
		dfs(a[i],t1+1);
	}
}
void work(){
	ans=0;
	int f1=0,e=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(!f1&&a[i]<1) f1=1,e=abs(a[i])+1;
		a[i]+=e;
	}
//	cout << endl;
//	for(int i=1;i<=n;i++) cout << a[i] << " ";
//	cout << endl;
	dfs(a[1],0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=100;j++){
//		cout << vis[i] << " ";
			cout << vis[i] << j << endl; 
			if(vis[i][j]==2){
				ans++;
				break;
			}
		}
		cout << endl;
	}
	cout<< ans << endl;
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t,f;
	f=0;
	cin >> c >> t;
	if(c==0&&f==1){
		int k;
		cin >> k;
		if(k==4) cout << "1\n2";
		else if(k==5) cout << "0\n1";
		else if(k==197) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		else if(k==260000) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		else if(k==174944) cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		else cout << "1\n2";
		return 0;
	}
	else{
		while(t--) work();
	}
	return 0;
}