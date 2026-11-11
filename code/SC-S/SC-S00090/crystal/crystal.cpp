#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;
	long long m,a[n];
	vector<long long>s;
	cin>>m;
	long long sz=0,gs=0,ds=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		sz=0,gs=0;
		
		for(int j=i;j>=0;j--){
			s.push_back(abs(a[i]-a[j]));
			gs=abs(i+1-j);
			sz+=abs(a[i]-a[j]);
		}
		cout<<gs<<' '<<sz<<' ';
		
		sort(s.begin(),s.end());
		while(sz>m){
			sz-=s[s.size()-1];
			s.pop_back();
			gs--;
		}
		cout<<gs<<" "<<sz<<endl;
		s.clear();
		if(gs>ds)ds=gs;
	}cout<<ds;
	gs=0;
	sz=0;
	s.clear();
	ds=0;
	return 0;
}