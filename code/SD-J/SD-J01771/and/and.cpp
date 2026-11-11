#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int a[N],mx=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	system("fc and5.out and5.ans");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=2000&&m<=2){
		for(int i=1;i<=n;i++){
			for(int i=1;i<=m;i++){
				mx=max(mx,a[i]&a[i+1]);
			} 
//			mx=max(mx,a[i]&a[i+1]);
		} 
	} 
	cout<<mx;
	return 0;
} 
