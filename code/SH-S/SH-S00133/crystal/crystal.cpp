#include<bits/stdc++.h>
using namespace std;
int a[1000005],d[1000005];//cha
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;

	long long int x=0x3f3f,y;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i!=0) {
			d[i-1]=abs(a[i]-a[i-1]);
			if(d[i-1]<x) {
				x=d[i-1];
				y=i-1;
			}
			//cout<<d[i-1]<<" ";
		}
	}
//  cout<<endl<<endl;
	// cout<<"x"<<x<<" y"<<y<<endl<<endl;
	long long int ans=0,answer=0,k=y,p=y;//ans right answer left
	//for(int i=0;i<n-1;i++)
	// {
	//	cout<<d[i]<<" ";
	//}
//	cout<<endl<<endl;;
	while(ans<m&&k<n-1) {

		ans+=d[k];
		k+=1;
		//	cout<<ans<<endl<<endl;

	}
	while(ans<m&&p>=0) {
		answer+=d[k];
		p-=1;
	}
	//cout<<"min"<<y<<endl;
	//cout<<"ans"<<ans<<"  answer"<<answer<<endl;
	//cout<<"k"<<k<<" p"<<p<<endl;
	cout<<max(k,p);

	return 0;
}
