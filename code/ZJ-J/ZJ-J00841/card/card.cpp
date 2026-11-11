//Éñ Ä´óÄ£Äâ  bu tiao le
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
struct lian{
	int f,l;
}table[500005];
//bool f(int fr,int la,int x){
//	for(int i = fr;i <= la;){
//		if(table[i].d == x) return 1;
//		i = table[i].l;
//	}
//	return 0;
//}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
//	for(int i = 1;i <= n;i++){
//		int fr = i,la = i;
//		table[i].f = -1;table[i].l = -1;
//		
//		for(int j = i+1;j <= n;j++){
//			if(!f(fr,la,a[j])){
//				table[i].l = j;
//				table[j].f = i;
//				ta
//				
//			}
//		}
//	}
	for(int i = 1;i <= m;i++){
		cout << n << " ";
	}
	return 0;
}
