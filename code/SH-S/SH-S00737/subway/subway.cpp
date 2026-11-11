#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;//È¥x£¬»¨y 
};
long long c,n,m,d,q,w[500010],k,a[500010],t[500010],f[510][510],ans;
long long l,r,mid;
vector<node>ve[500010];
void solve(int num){
	l=num;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
		mid=a[i];
		for(int j=0;j<ve[mid].size();j++){
			r=ve[mid][j].x;
			f[l][r]=f[r][l]=min(f[l][r],t[i]+ve[mid][j].y);
		}
		ve[mid].push_back({l,t[i]});
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		solve(i);
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][mid]+f[mid][j]);
			}
		}
	}
	while(q--){
		ans=1e18;
		cin>>l>>r;
		for(int i=0;i<ve[l].size();i++){
			for(int j=0;j<ve[r].size();j++){
				ans=min(ans,ve[l][i].y+ve[r][j].y+f[ve[l][i].x][ve[r][j].x]);
			}
		}
		cout<<w[l]+w[r]+ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
