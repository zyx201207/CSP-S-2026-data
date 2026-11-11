#include <bits/stdc++.h>
using namespace std;
int main(){
//	fecopen("travel.in","r",stdin);
//	fecopen("travel.out","w",stdout);
	int n;
	cin >> n;
	int s[200005],a[200005],c[200005];
	for (int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for (int j=0;j<a[i];j++){
			c[i] = s[i];
		}
	}
	
//	fclose(stdin);fclose(stdout);
	return 0;
}
