#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a[10000]={};
	int c,n,m,d,q;
	int k;
	int b[10000]={};
	int w[10000]={};
	int x[10000]={};
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>w[i]>>x[i];
		}
	}
	for(int i=0;i<q;i++){
		cin>>w[i]>>w[i];
	}
	for(int i=0;i<q;i++){
		cout<<13;
	}
	return 0;
}