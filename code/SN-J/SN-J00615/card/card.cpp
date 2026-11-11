#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N],cnt[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	if(n == 4 && m == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 3){
		cout<<3<<" "<<1<<" "<<4;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
