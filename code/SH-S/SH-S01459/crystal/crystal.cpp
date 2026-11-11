#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a;
	queue<int> r;
	long long n,m,nd=0,M=0;
	long long ls;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>ls;
		a.push_back(ls);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		r.push(a.back());
		nd+=r.front()-r.back();
	
		while(nd>m){
			ls=r.front();
			r.pop();
			
			
			nd-=(ls-r.front())*r.size();
			
		}
		if(r.size()>M)M=r.size();
		a.pop_back();
	}
	cout<<M<<endl;
	return 0;
}
