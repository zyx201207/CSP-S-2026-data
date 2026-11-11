#include<bits/stdc++.h>
const int N=2e5+5;
int a[N];
int t[N];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long cnt=0;
	int mx=-1;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
		t[a[i]]++;
	}
	for(int i=1;i<=mx;i++){
		if(t[i]>=1) cnt++;
	}
	if(t[mx]>1){
		cout << mx;
		return 0;
	}
	
	
	return 0;
}
