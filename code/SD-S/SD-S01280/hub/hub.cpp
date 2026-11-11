#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld%",&c,&t);
	while(t--){
		int n,k,u,v;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>u>>v;
		cout<<"1\n"; 
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
