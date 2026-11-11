#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+10;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
int c,t,n;
ll d;
ll x[N];
ll cnt = 0;
int line = 0;
void dfs(int start,int end,int n){
//	cout << start << " " << end << " " << n << endl;
	if (x[end]-x[start]<=d && n==2){
//		cout << start << "--" << end << endl;
		line ++;	
	} 
	
	for (int i = start+1;i < end;i ++){
		if (x[i]-x[start] <= d){
			dfs(i,end,n+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t --){
		cnt = 0;
		cin >> n >> d;
		for (int i = 0;i < n;i ++) cin >> x[i];
		
		for (int i = 0;i+3 < n;i ++){
			for (int j = i+3;j < n;j ++){
				line = 0;
				dfs(i,j,1);
				if (line == 2) cnt ++;
			}
		}
		cout << cnt << endl;
		
	}

	return 0;
}