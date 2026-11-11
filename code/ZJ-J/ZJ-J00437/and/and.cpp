#include<bits/stdc++.h>
using namespace std;
int n,m;
void print(vector<int> v) {
	for(int i=0; i<v.size(); i++) cout<<v[i]<<' ';
	cout<<'\n';
}
void cl(vector<int> &v,int m) {
	int b[35]= {0};
	for(int i=0; i<v.size(); i++) {
		int x=v[i];
		int l=0;
		while(x) {
			b[l++]+=x&1;
			x>>=1;
		}
	}
	vector<int> vv;
	for(int i=30; i>=0; i--) {
		if(b[i]>=m) {
			for(int j=0; j<v.size(); j++) {
				if(v[j]>>i&1) vv.push_back(v[j]);
			}
			break;
		}
	}
	v=vv;
	
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> v;
	for(int x,i=1; i<=n; i++) {
		cin>>x;
		v.push_back(x);
	}
	int num=0,a;
	for(int qwq=1; qwq<=30; qwq++) {
		a=INT_MAX;
		cl(v,m);
		for(int i=0; i<v.size(); i++) a=a&v[i];
		if(a==INT_MAX) break;
		num+=a;
		for(int i=0; i<v.size(); i++) v[i]-=a;
	}
	cout<<num;
}
