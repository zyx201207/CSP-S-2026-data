#include<bits/stdc++.h>
using namespace std;
int n,m,max1=0,max2=0,m1=0,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m==n){
		max1 = a[0];
		for(int i=1;i<n;i++){
			max1 = a[i]&max1;
		}
		cout << max1;
		return 0;
	}
	if(m==1){
		sort(a,a+n+1);
		cout << a[n];
		return 0;
	}
	if(m == n-1){
		max1 = a[0];
		max2 = a[1];
		for(int i=0;i<m;i++){
			max1 = a[i]&max1;
		}
		for(int i=0;i<n;i++){
			max2 = a[i]&max2;
		}
		cout << max(max1,max2);
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(max2>max1){
					max1 = max2;
				}
				max2 = a[i]&a[j];
				cout << a[i]  << " " << a[j] << " " << (a[i]&a[j]) << endl;
			}
		}
		cout << max1;
		return 0;
	}
	max2 = a[0];
	for(int i=0;i<n-m;i++){
		x = i*(m-1);
		while(m1==m-1){
			max2 = max2&a[x+m1];
			m1++;
		}
		if(max2>max1){
			max1 = max2;
		}
	}
	cout << max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
