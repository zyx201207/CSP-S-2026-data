//王梓桐 SN-J00849 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	printf("%d",a[n-m]);
	return 0;
}
