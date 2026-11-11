#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int M = 5e5+10;

int c,n,m,d,q;
int W[M];
int line[510][M];
int f(int start,int end){
	int t = INT_MAX;
	for (int i = 0;i < n;i ++){
		if (line[i][start]>=1){
			if (line[i][end]>=1) t = min(line[i][end],t);
			else t = min(t,f(i,end));
		} 
	}
	return t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0;i < m;i ++) cin >> W[i]; 
	for (int i = 0;i < n;i ++){
		int k;
		cin >> k;
		for (int j = 0;j < k;j ++){
			int a,t;
			cin >> a >> t;
			line[i][a] = t;
		}
	}
	
	while (q --){
		int t = 0;
		int start,end;
		cin >> start >> end;
		t += W[start];
		t += W[end]; 
		t += f(start,end);
		cout << t << endl;
	}

	return 0;
}
