#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int w[N],c[N],n,m;
bool check(int a){
	//cout<<"xuhuan "<<a<<'\n';
	int cos=INT_MAX;
	for(int i=1;i+a-1<=n;i++){
		int dis=0;
		//cout<<i<<endl;
		for(int j=1;j<a;j++){
			dis=dis+c[i+j]*j;
			//cout<<"dis"<<' '<<dis<<'\n';
		}
		cos=min(cos,dis);
		//cout<<"cos"<<' '<<cos<<'\n';
	}
	//cout<<"cos"<<' '<<cos<<'\n';
	return cos<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int te=0;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]==i) te++;
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++){
		c[i]=w[i]-w[i-1];
	}
	int lf=1,rt=n,ans=1;
	while(lf<=rt){
		int mid=lf+(rt-lf)/2;
		if(check(mid)){
			ans=mid;
			lf=mid+1;
		}
		else rt=mid-1;
	}
	/*for(int i=1;i<=n;i++){
			cout<<c[i]<<' '; 
	}*/
	cout<<ans;
	return 0;
}
