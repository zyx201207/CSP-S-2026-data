#include <bits/stdc++.h>
using namespace std;
int n,m,s,c[40],a[200010];
bool g[40][200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (int j=0;j<30;j++)
			if (a[i]&(1<<j)){
				g[j][i]=true;
				++c[j];
			}
	}
	for (int i=29;i>=0;i--)
		if (c[i]>=m){
			s|=1<<i;
			for (int j=i-1;j>=0;j--)
				for (int k=1;k<=n;k++)
					if (!g[i][k]&&g[j][k]){
						g[j][k]=false;
						--c[j];
					}
		}
	cout<<s<<"\n";
	return 0;
}
