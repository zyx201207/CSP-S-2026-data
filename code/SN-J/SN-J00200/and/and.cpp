#include<bits/stdc++.h>
using namespace std;
int n,m,t=0;
int main(){
	preopen("and.in","cin",stdin);
	preopen("and.out","cout",stdout);
	cin>>n>>m;
	vector<int> q,w;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	for(int j=0;j<n;j++){
		for(int r=0;r<=n;r++){
			if(t<q[r]) t=q[r];
		}
		w[j]=t;
	}
	cout<<w[m-1];
	return 0;
}
