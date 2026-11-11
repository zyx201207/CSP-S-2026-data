#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> qz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int p,ans=0,ma=0,zs;
	cin>>n>>m;
	for( int i=1;i<=n;i++){
		cin>>p;
		v.push_back(p);
	}
	for(int j=0;j<n;j++){
		qz.push_back(v[j]-v[j-1]);
	}
	int k=n,cu=m;
	if(n<=5000){
		for( int i=n;i>=0;i--){
		ans=0;
		m=cu;
		int z=0;
			for(int j=i;j>=0;j--){
				if(m-z<0){
					continue;
				}
				else if (m-z>0){
					z+=qz[j];
					m-=z;
					ans+=1;
				}
		}
		ma=max(ma,ans);	
		}
	}
	else if(qz[3]==qz[50]){
		zs=2*m/qz[3];
		for(int i3;i3<=zs/80;i3++){
			if(i3*i3==zs);
				ma=i3;
		}
			
	}	
	cout<<ma;
	return 0;
	
}
