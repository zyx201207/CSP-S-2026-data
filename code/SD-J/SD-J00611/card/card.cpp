#include <bits/stdc++.h>
using namespace std;
int a[500005],t[500005],t1[500005];
vector<int> v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			cout<<l<<endl;
			if(v[a[l]].size()>1){
				t1[a[l]]++;
				l=v[a[l]][t1[a[l]]];
			}
			else{
				l++;
				t[a[l]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
