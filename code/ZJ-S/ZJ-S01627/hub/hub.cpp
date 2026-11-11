#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[4005][4005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1;i<n;i++){
			int s,t;
			scanf("%d %d",&s,&t);
			a[s][t] = a[t][s] = 1;
		}
		if(k<=2){
			cout << k-1 << endl;
			continue;
		}
	}
}