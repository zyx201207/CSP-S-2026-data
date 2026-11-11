#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxs=0,c;
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (m==2){
		for (int i=1;i<=n;i++){
	
			
			c=(a[i] & a[i+1]);
			if (c > maxs){
				maxs=c;
			}
		}
	}
	cout << maxs;
	return 0;
}
