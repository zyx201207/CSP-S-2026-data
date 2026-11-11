#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,arr[N],ans[N],pos[N],num[N];
void solve(int l){
	memset(pos,-1,sizeof pos);
	memset(num,-1,sizeof num);
	int tail=0;
	for(int i=l;i<=n;++i){
		int tmp=pos[arr[i]];
		if(tmp!=-1){
			tail=tmp;
			memset(num+tmp,-1,sizeof num);
		}else{
			++tail;
		}
		num[tail]=arr[i];
		pos[arr[i]]=tail;
	}
	for(int i=1;i<=tail;++i){
		++ans[num[i]];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	for(int i=1;i<=n;++i){
		solve(i);
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}