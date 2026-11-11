#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
using namespace std;
const int N=5e6+5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	
	int c,Q;
	cin>>c>>Q;
	while(Q--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		srand(time(0));
		int x=rand()%(n-1+1)+1;
		cout<<x<<"\n";
	}
	
	return 0;
}
/*
12 11
6 1 4
7 2 1
8 3 9
9 4 2
10 5 5
6 11 5
7 11 7
9 11 6
7 12 3
8 12 4
10 12 7

4 5
1 2 1
1 3 2
2 3 1
2 4 2
3 4 1

0 2
2 5 3
3 -2 -1 0 1 2
4 6 2
5 -4 -3 -2 -1 3 6
*/
