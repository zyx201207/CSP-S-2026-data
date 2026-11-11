#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a[505],t[505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		vector<int> v;
		for(int i=k;i<n;i++){
			bool f=0;
			for(int j=0;j<v.size();j++){
				if(f) v[j]=0;
				if(v[j]==a[i]){
					f=1;
					v[j]=a[i];
				}
			}
			if(!f) v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++){
			t[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
