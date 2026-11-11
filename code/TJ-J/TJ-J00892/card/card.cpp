#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans[200010];
bool tmp[200010];
vector<int>aaa;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		if(tmp[a[i]]){
			auto *q = lower_bound(aaa.begin(),aaa.end(),a[i]);
			aaa.erase(q,aaa.end());
		}
		tmp[a[i]] = true;
		aaa.push_back(a[i]);
		for(int i = 1;i <= m;i++){
			if(tmp[a[i]]) ans[a[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " "; 
	}
	return 0;
}
