#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[500001],t[500001];
bool c_F(int k){
	for(int i=0;i<v.size();i++){
		if(v[i]==k) return false;
	}
	return true;
}
int f(int k){
	for(int i=0;i<v.size();i++){
		if(v[i]==k) return i;
	}
	return 0;
}
bool c_A(int n){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) return false;
	}
	return true;
}

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c_A){
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]) cout<<i-1<<' ';
			if(i==n-1) cout<<i;
		}
		return 0;
	}

	for(int j=1;j<=n;j++){
	//	cout<<j<<endl<<endl;
		for(int i=j;i<=n;i++){
		
			if(c_F(a[i])) v.push_back(a[i]);
			else{
				for(int l=f(a[i]);l<=v.size()+1;l++){
					if(!v.empty()) v.pop_back();
				}
				if(v[v.size()-1]==v[v.size()-2]&&!v.empty()) v.pop_back();
				v.push_back(a[i]);
			}
		//	for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
		//	cout<<endl;
		}
		for(int i=0;i<v.size();i++) t[v[i]-1]++;
		v.clear();
	}
	for(int i=0;i<m;i++){
		cout<<t[i]<<' ';
	}
	
	return 0;
}
