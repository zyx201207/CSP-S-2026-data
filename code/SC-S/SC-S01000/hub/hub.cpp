#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, p[500005],jianjv=0;

int abs(int l){
	if(l<0)return l*(-1);
		else return l;
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		for (int j = 1; j <= n * 2 - 2; j++) {
			cin >> p[j];
		}
		sort(p+1,p+2*n-2,greater<int>());
		for(int j=1;j<=n*2-2;j++){
		
			if(abs(p[j]-p[j+1])>jianjv){
				jianjv=abs(p[j]-p[j+1]);
				
			}
		}
		cout<<jianjv/5<<endl;
		
	}
	return 0;
}

