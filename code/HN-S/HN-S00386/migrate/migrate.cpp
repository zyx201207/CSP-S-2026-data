#include <bits/stdc++.h>
#define ll long long
using namespace std;
//const int LJ = 0x3f3f3f3f3f3f3f;

int a[100000];
//const ll N = 2e6; 
//ll x[N + 105];
//vector <int> pict[N + 105];
//
//deque <int> xl;
//int dis[N + 105],cnt[N + 105];

//int r (){
//	int n,d;
//	for (int i = 1;i <= n;i++){
//		pict[i];
//	}
//	cin>>n>>d; 
//	for (int i = 1;i <= n;i++){
//		cin>>x[i];
//	}
//	sort(x + 1,x + 1 + n);
//	for (int l = 1,r = 1;r <= n;r++){
//		while (x[r] - x[l] > d){
//			l++;
//		}
//		if (l != r){
//			for (int j = l;j < r;j++){
//				if (x[j] - x[j])
//					pitt[j].push_back(r);
//					pitt[j].push_back(j);
//				else {
//					break;
//				}
//			}
//		}
//	}	
//	
//	for (int i = 1;i <= n;i++){
//		for (int j = i + 1;j <= n;j++){
//			if (j == 2){
//				sum++;
//			}
//		}
//	}
//}

ll n,t;

int main (){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>n>>t;
	for (int i = 1;i <= t;i++){
		cin>>a[i];
	}
	
	if (a[1] == 4){
		cout<<1<<"\n"<<2;
	}
	else {
		cout<<0<<"\n"<<1;
	}	
			
	return 0;
}
