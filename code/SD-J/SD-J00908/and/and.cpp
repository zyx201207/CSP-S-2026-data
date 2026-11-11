#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool YN[200005];
vector<int> cnt[50];
void chaiwei(){
	for(int i=0;i<=30;i++){
		cnt[i].clear();
	}
	for(int i=1,t,j;i<=n;i++){
		if(YN[i]!=0)continue;
		t=a[i],j=-1;
		while(t){
			++j;
			if(t&1){
				cnt[j].push_back(i);
			}
			t>>=1;
		}
	}
	memset(YN,-1,sizeof YN);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,t,j;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	chaiwei();
	memset(YN,-1,sizeof YN);
	for(int i=30;i>=0;i--){
		if(cnt[i].size()>=m){
			ans|=(1<<i);
			for(int j=0;j<cnt[i].size();j++){
				YN[cnt[i][j]]=0;
			}
			chaiwei();
		}
	}
	cout<<ans;
//	for(int i=0;i<=30;i++){
//		for(size_t j=0;j<cnt[i].size();j++){
//			cout<<cnt[i][j]<<" "; 
//		}
//		cout<<"\n"; 
//	}
	return 0;
}

