#include<bits/stdc++.h>
using namespace std;
const int N =5e5+7;
const int M =3e5+7;
int n,m,a[N],b[M];
map<int,int> mp;
vector<int> vc[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			mp[a[i]]=i;
			vc[i].push_back(a[i]);
			continue;
		}
		if(mp[a[i]]==0){
			mp[a[i]]=i;
			vc[i]=vc[i+1];
			vc[i].push_back(a[i]);
		}
		else{
			vc[i]=vc[mp[a[i]]];
			mp[a[i]]=i;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(auto j :vc[i]){
			b[j]++;
		}
	}
	

	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
