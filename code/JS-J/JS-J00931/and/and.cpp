#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],cnt[31],ans;
vector<int>b[31],c[31];
void add(int x){
	for(int i=30;i>=0;--i)if(x&(1<<i))++cnt[i],b[i].push_back(x);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],add(a[i]);
	for(int i=30;i>=0;--i)sort(b[i].begin(),b[i].end(),cmp);
	for(int i=30;i>=0;--i){
		if(cnt[i]>=m){
			ans+=1<<i;
			for(int z=i-1;z>=0;--z){
				int s=0;
				c[z].clear();
				for(int j=0,k=0;j<(int)b[i].size()&&k<(int)b[z].size();++j){
					while(b[i][j]<b[z][k]&&k<(int)b[z].size())++k;
					if(b[i][j]==b[z][k])c[z].push_back(b[i][j]),++s;
				}
				swap(b[z],c[z]);
				cnt[z]=s;
			}
		}
	}
	cout<<ans;
	return 0;
}
