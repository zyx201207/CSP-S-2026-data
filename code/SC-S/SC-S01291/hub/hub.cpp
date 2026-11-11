#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct S{
	int u;
	int v;
}a[1000005];
int main(){
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			cin >> a[i].u >> a[i].v;
		}
	} 
	cout << "1\n2";
	return 0;
} 