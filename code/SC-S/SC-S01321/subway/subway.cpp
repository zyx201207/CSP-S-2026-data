#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;
struct node{
	int a;
	int t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	node l[maxn]={{0,0}};
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m+1);
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> l[j].a >> l[j].t;
		}
	}
	for(int i = 1; i <= q; i++){
		int x,y;
		cin >> x >> y;
		for(int j = 1; j <= n; j++){
			if(l[j].a == y){
				cout<<w[1]+l[j].t+w[l[j].a-1]+w[i]+l[j+i-9].t<<endl;
			}
		}
	}
	return 0;
}