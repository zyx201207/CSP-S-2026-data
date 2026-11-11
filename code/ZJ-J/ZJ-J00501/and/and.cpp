#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool a[200005][31];
int b[200005];
map<int,int> c;
map<int,int> d;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		b[i]=x;
		c[b[i]]++;
	}
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		int x=b[i];
		int now=1;
		while(x){
			a[i][now]=x%2;
			d[now]+=x%2;
			now++;
			x/=2;
		}
	}
	map<int,int> ans;
	int sum=0;
	for(int i=30;i>=1;i--){
		if(sum>=m) break;
		for(int j=1;j<=n;j++){
			if(sum>=m) break;
			if(d[i]>=m-sum){
				if(a[j][i]){
					if(ans[b[j]]<c[b[j]]){
						ans[b[j]]++;
						sum++;
					}
				}
			}
		}
	}
	int anss=-1;
	for(auto t:ans){
		if(anss==-1){
			anss=t.first;
		}else{
			anss&=t.first;
		}
	}
	cout<<anss;
	return 0;
}
