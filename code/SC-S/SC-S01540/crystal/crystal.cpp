#include <bits/stdc++.h>
using namespace std;
void add(int a,int b){
	
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);

	//ios::sync_with_stdio(0);
	int a[10086];
	vector<int> b,c;
	int m,n,cnt;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		int d[100008];
		d[i]=a[i];
		for(int j=0;j<n;j++){
			if(d[i]==a[i+1]) cnt++;
		}
	}
	for(int i=0;i<cnt-n;i++) c.push_back(0);
	for(int i=1;i<=n;i++) {
		//if(i==0) {continue;}
		int s=0;
		for(int j=0;j<n;j++){
			
			s=s+a[i]-a[i-j];
		}
		b.push_back(m);
		b.push_back(s);
	}
	for(int i=0;i<n;i++){
		//cout<<b[i]<<' ';
		if(b[i]<=m) {
			c.push_back(i);}
	}
	cout<<c.size();
	return 0;
}