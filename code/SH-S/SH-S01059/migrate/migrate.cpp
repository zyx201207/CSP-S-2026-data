#include<bits/stdc++.h>
using namespace std;

const int maxn=2000006;
int c, t, n;
long long pos[maxn], d, ans[5002][5002], oout;


int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	while(t--) {
		memset(ans, 0, sizeof(ans));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pos[i];
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(pos[j]-pos[i]<=d) ans[i][j]=1;
			}
		}
		
		for(int kkk=1;kkk<=n;kkk++) {
			for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(ans[i][j]) continue;
				for(int k=i;k<=j;k++) {
					if(pos[k]-pos[i]>d || pos[j]-pos[k]>d) 
						continue;
					ans[i][j]+=(ans[i][k]*ans[k][j]);
				}
			}
		}
		}
		
		oout=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) 
			if(ans[i][j]==2) oout++;
		cout<<oout<<'\n';
	}
	
	fclose(stdin);
	return 0;
}
