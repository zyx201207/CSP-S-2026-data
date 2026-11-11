#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<a[m-1]<<endl;
	return 0;
}
//I will AFO on CSP-2026
//goodbye my OI dream QWQ TT
//luogu id tuotuoyl(别看) 
//祝我whk加油 11:50 别炸
