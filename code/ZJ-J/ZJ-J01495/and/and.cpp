#include<bits/stdc++.h>
using namespace std;
const int LOG=30;
int n,m;
long long ans=(1<<(LOG+1))-1;
int a[200010];
vector<int>v[35];
queue<int>d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int A=a[i];
		for(int j=LOG;j>=0;j--){
			if(A>=(1<<j)){
				A-=(1<<j);
				v[j].push_back(i);
			}
		}
	}
	int i=LOG;
	for(;i>=0;i--){
		if(v[i].size()<m)continue;
		for(int j=0;j<v[i].size();j++){
			d.push(v[i][j]);
		}
		break;
	}
	for(;i>=0;i--){
		//cout<<i<<":  ";
		int y=0;
		int tu=d.size();
		for(int j=0;j<tu;j++){
			int t=d.front();
			d.pop();
			if((a[t]&(1<<i))==0)y++;
			d.push(t);
		}
		if(d.size()-y>=m){
			for(int j=0;j<tu;j++){
				int t=d.front();
				d.pop();
				if((a[t]&(1<<i)))d.push(t);
			}
		}
	}
	for(int j=0;j<m;j++){
		ans&=a[d.front()];
		d.pop();
	}
	cout<<ans;
	return 0;
} 
