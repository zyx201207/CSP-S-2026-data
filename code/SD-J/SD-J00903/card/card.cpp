#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	int ac=0;
	int goal[m+5]={0};
	int ans[n+5]={0};
	for(int i=0;i<n;i++){
		cin>>ans[i];
	}
	while(n--){
		for(int i=ac;i<n;i++){
			for(int j=0;j<a.size();j++){
				if(a[i]==a[j]){
					for(int k=0;k<i-j+1;k++){
						a.pop_back();
					}
				}
			}
			int x=ans[i];
			a.push_back(x);
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<=a.size();j++){
				if(i==a[j]){
					goal[i]++;
				}
			}
		}
		ac++;
		for(int i=0;i<a.size();i++){
			a.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<goal[i]<<" ";
	}
	return 0;
} 
