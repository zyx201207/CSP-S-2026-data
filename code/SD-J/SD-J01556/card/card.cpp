#include <bits/stdc++.h>
using namespace std;
int c[30000+50];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	a.push_back(0);
	for(int i=0;i<n;i++){
		int a_;
		cin>>a_;
		a.push_back(a_);
	}
	for(int i=1;i<=n;i++){
		vector<int> d;
		for(int j=i;j<=n;j++){
			for(int k=0;k<d.size();k++){
				if(d[k]==a[j]){
					for(int l=k;l<d.size();) d.erase(d.begin()+k);
				}
			}
			d.push_back(a[j]);
		}
		for(int j=0;j<d.size();j++) c[d[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
