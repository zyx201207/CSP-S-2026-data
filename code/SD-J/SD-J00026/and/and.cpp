#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[33][N],deled[N],
cnt[33],anss[33];
void tobinf(int i){
	int ii=i;
	i=a[i];
	vector<int>ans;
	while(i){
		ans.push_back(i%2);
		i/=2;
	}
	for(int j=0;j<ans.size();j++){
		b[j][ii]=ans[j];
		cnt[j]+=ans[j];
	}
}void delnum(int x){
	deled[x]=1;
	for(int i=0;i<33;i++)
	cnt[i]-=b[i][x];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tobinf(i);
	}for(int i=32;i>=0;i--){
		if(cnt[i]<m)continue;
		else{
			anss[i]=1;
			for(int j=1;j<=n;j++)
			if(b[i][j]==0&&!deled[j])
			delnum(j);
		}
	}int ans=0;
	for(int i=0;i<33;i++)
	ans+=((1<<i)*anss[i]);
	cout<<ans;
	return 0;
}
