#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[200005][35],s[35],ans=0;
vector<int>ve[35];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long pos=1;
		for(int j=1;j<=31;j++){
			if(a[i]&pos)c[i][j]=1;
			else c[i][j]=0;
			pos*=2;
			if(c[i][j]==1){
				ve[j].push_back(i);
				s[j]++;
			}
		}
	}
	bool ck=0;
	int sum=0;
	for(int i=31;i>=1;i--){
		if(s[i]<m)continue;
		if(sum>=m||(ck==0&&s[i]>=m))ans+=(1<<(i-1));
		if(ck==0){
			for(int j=i-1;j>=0;j--){
				ve[j].clear();
			}
			ck=1;
		}
		sum=0;
		for(auto it:ve[i]){
			if(c[it][i-1]==1){
				sum++;
				ve[i-1].push_back(it);
			}
		}
		if(sum<m)break;
	}
	cout<<ans<<endl;
	return 0;
}
