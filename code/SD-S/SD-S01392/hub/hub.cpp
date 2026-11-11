#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,n,k;
vector<int> e[N];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y; i<n; i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y),e[y].push_back(x);
	} 
	printf("%d\n",rand()%n);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
/*
ren lei yi bai tu di
*/
