#include<bits/stdc++.h>
using namespace std;
int find(int i,vector<int>& t){
	for(int j=0;j<t.size();j++){
		if(t[j]==i){
			return j;
		}
	}
	return -1;
}
int main(){
	ifstream("card.in");
	ofstream("card.out");
	int m,n,p;
	cin >> n >> m;
	vector<int> ans(m+1);
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int k=0;k<n;k++){
		vector<int> t;
		for(int i=k;i<n;i++){
			p=find(a[i],t);
			if(p!=-1){
				t.erase(t.begin()+p,t.end());
			}
			t.push_back(a[i]);
		}
		for(int j=0;j<t.size();j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
