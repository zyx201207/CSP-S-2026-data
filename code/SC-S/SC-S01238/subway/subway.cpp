#include<bits/stdc++.h>
using namespace std;
struct A{
	int name;
	int time;
	vector<A*> to;
	vector<A*> from;
};
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	vector<A> a(n);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int cnt,tnc;
			cin>>cnt>>tnc;
			a[i].name=cnt;
			a[i].time=tnc; 
			if (j<k-1)a[j].from.push_back(&a[j-1]);
			if(j>0) a[j-1].to.push_back(&a[j]);
		}
	}
	int r;
	cin>>r;
	for(int i=0;i<r;i++){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<n){
			if(a[i].name!=x){
				continue;
			}
			
		}
	}
	return 0;
}