#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans=0;
int d[40];
vector<int> notused[40];
bool vis[maxn];
void detail(int x){
	for(int k=1;k<=31;k++){
		if((x&(1<<(k-1)))>0){
			d[k]--;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int k=1;k<=31;k++){
			int x=1<<(k-1);
			if((a[i]&x)==0){
				notused[k].push_back(i);
			}
			else{
				d[k]++;
			}
		}
	}
	for(int k=31;k>=1;k--){
		if(d[k]>=m){
			ans|=1<<(k-1);
			for(int i:notused[k]){
				if(!vis[i]){
					detail(a[i]);
					vis[i]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}