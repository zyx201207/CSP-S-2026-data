#include<bits/stdc++.h>
using namespace std;
vector<char> s;
int n;
vector<int> a;
vector<int> ans;
int m;
int num;
int main(){
	/*
	4 2
	3 15 12 12
	*/
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int aaa = 0;
		cin >> aaa;
		a.push_back(aaa);
		
	}
	for(int j = 0; j < n; j++){
		for(int i = 1; i <= m; i++){
			for(int l = i-1; l < n; l++){
				cout << "aaa ";
				ans[i]  = (s[i-1] & s[l]);
				num++;
			}
	}
}
	sort(ans.begin(),ans.end());
	
	cout << ans[num-1];
	return 0;
}
