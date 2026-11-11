#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t;
	int a[300000];
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < i;j++){
			if(a[j] > a[j-1]){
				a[j] = t;
				a[j-1] = a[j];
				a[j] = a[j-1];
			}
		}
	}
	int cnt = a[0];
	for(int i = 1;i < m;i++){
		cnt = cnt & a[i];
	}
	cout << cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}