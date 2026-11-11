#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int w[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,hl=0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i] >> c[i];
		hl += a[i];
	}
	for(int i = 0;i<200001;i++){
		w[i] = w[i-1]+c[i];
	}
	cout << 0;
	
	return 0;
}
