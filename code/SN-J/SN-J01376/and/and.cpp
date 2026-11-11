#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int W,x;
	int n,m,kk;
	cin>>n;
	cin>>m;
	vector<int> l;
	for(int i=0;i<n;i++){
		cin>>kk;
		l.push_back(kk);
	}
	sort(l.begin(),l.end());
	reverse(l.begin(),l.end());
	int sun=l[0];
	for(int j=1;j<m;j++){
		sun=sun&l[j];
	} 
	cout<<sun;
	return 0;

}
