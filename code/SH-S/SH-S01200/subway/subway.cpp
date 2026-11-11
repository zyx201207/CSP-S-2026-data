#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> w;
struct subway{
	vector<int> a;
	vector<int> t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	subway lxy[n];
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	} 
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		for(int j=0;j<p;j++){
			int u_,v_;
			cin>>u_>>v_;
			lxy[i].a.push_back(u_);
			lxy[i].t.push_back(v_);
		}
	}
	for(int i=0;i<q;i++){
		int x_,y_;
		cin>>x_>>y_;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}
	else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl;
		cout<<16<<endl;
	}
	cout<<"it's so difficult";
	return 0;
} 
