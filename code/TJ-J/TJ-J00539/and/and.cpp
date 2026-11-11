#include<bits/stdc++.h> 
using namespace std;

int n,m,sum = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	for(int i = 0;i < m;i++){
		sum = a[i]&a[i+1];
	}
	cout << sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
