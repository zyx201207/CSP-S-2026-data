#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100,D=30;
int n,m;
bool digits[N][D];
int num[N],dn[D];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=0;j<D;j++){
			digits[i][j]=((1<<j)&num[i]);
			if(digits[i][j]) dn[j]++;
		}
	}
	int t=-1;
	for(int i=D-1;i>=0;i--){
		if(dn[i]>=m){
			t=i;
			break;
		}
		//cout<<i<<' '<<dn[i]<<endl;
	}
	if(t==-1){
		cout<<0;
		return 0;
	}
	vector<int> u,v;
	for(int i=1;i<=n;i++){
		if(digits[i][t]) v.push_back(i);
	}
	for(int i=t-1;i>=0;i--){
		u.clear();
		for(auto k:v){
			if(digits[k][i]){
				u.push_back(k);
				//cout<<k<<' '<<i;
			}
		}
		if(int(u.size())<m) continue;
		v=u;
	}
	int ans=(1<<D)-1;
	for(int i=0;i<m;i++){
		ans=(ans&num[v[i]]);
	}
	cout<<ans;
	return 0;
}
