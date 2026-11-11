#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,temp;vector <int> nu,nu2;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>temp;
		nu.push_back(temp);
	}
	
	for(int i = n;i > 0;i--){
		for(int p = 0;p < n;p++){
			nu2.push_back(nu[p]);
			for(int _i = 1;_i <= m;_i++) nu2[p] &= nu[_i+1];
		}
	}

	sort(nu2.begin(),nu2.end());
	cout<<nu2[n];
	return 0;
}
