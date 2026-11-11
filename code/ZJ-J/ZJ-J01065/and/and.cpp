#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int awy(int i,int j,int m1){
	m1=m1&a[i];
	int maxx=m1;
	if(j==1){
		return m1;
	}
	while(i<n-j+1){
		int b=awy(i+1,j-1,m1);
		maxx=max(maxx,b);
		i++;
	}
	return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int b;
		cin >> b;
		a.push_back(b);
	}
	int maxx=0;
	for(int i=0;i<n-m+1;i++){
		maxx=max(maxx,awy(i+1,m-1,a[i]));
	}
	cout << maxx;
	return 0;
}