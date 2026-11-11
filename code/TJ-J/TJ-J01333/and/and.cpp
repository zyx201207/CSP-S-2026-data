#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;//ÓÐnÑ¡m 
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());
	cout<<a[1];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
