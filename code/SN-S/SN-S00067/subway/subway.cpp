#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>first_time;
	vector<vector<int> >index;
	vector<vector<int> >second_time;
	vector<int>start;
	vector<int>end;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		first_time.push_back(x);
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		index[0].push_back(k);
		second_time[0].push_back(k);
		for(int j=1;j<=2*k;j++){
			int a,t;
			cin>>a>>t;
			index[j].push_back(a);
			second_time[j].push_back(t);
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		start.push_back(x);
		end.push_back(y);
	}
	
	return 0;
}

