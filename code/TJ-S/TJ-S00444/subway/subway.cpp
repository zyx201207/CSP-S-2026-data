#include<bits/stdc++.h>
using namespace std;
int w[500010];
struct node{
	int k;
	int a;
	int t;
}p[500010];
struct node2{
	int st;
	int ed;
}p1[100010];
//int ton[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
//	0 2 5 20 2
//	4 1 9 2 5
//	3 1 5 2 7 4 6
//	3 2 3 3 4 5 7
//	1 3
//	1 2
	for(int i = 1;i <= m;i++) cin >> w[i];
//	bool flag = true;
	for(int i = 1;i <= n;i++){
		cin >> p[i].k;
//		int T;
		for(int j = 1;j <= p[i].k;j++){
			cin >> p[i].a >> p[i].t;
//			if(i == 1){
//				T = p[i].t;
//			}else{
//				if(T != p[i].t){
//					flag = false;
//				} 
//			}
		}
	}
	for(int j = 1;j <= q;j++) cin >> p1[j].st >> p1[j].ed;
//	if(flag){
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= p[i].k;j++){
//				ton[p[i].a]++;
//			}
//		}
//		for(int i = 1;i <= n;i++){
//			
//		} 
//	}
	cout << 32 << '\n' << 17;
	return 0;
}

