#include<bits/stdc++.h>
using namespace std;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	ifstream("and.in");
	ofstream("and.out");
	int m,n,ans;
	cin >> m >> n;
	vector<int> a(m);
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),cmp);
	ans=a[0];
	for(int i=1;i<n;i++){
		ans=(ans&a[i]);
	}
	cout << ans;
}
