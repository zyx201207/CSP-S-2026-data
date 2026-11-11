#include<bits/stdc++.h>
using namespace std;
struct san{
	int a;
	int b[35];
	int masf;
};
bool ans(san a, san b){
	return a.masf>b.masf;
}
const int maxn = 2e5+5;
san a[maxn];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i].a;
		a[i].masf=0;
		int s=a[i].a;
		int j=1;
		while(s){
			a[i].b[j]=s%2;
			s/=2;
			if(a[i].b[j]==1){
				a[i].masf++;
			}
			j++;
		}
	}
	sort(&a[1], &a[n+1], ans);
	int d=a[1].a;
	for(int i=2;i<=m;i++){
		d=a[i].a&d;
	}
	cout << d;
	return 0;
} 
