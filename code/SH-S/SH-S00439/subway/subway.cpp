#include<bits/stdc++.h>
using namespace std;
int a[1005][2];
int w[1005];
struct node{
	int ki;
	int ik[1005];
}k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i].ki;
		for(int j=0;j<2*n;i++){
			cin>>k[i].ik[j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>a[i][0]>>a[i][1];
		int s=a[i][1]-a[i][0];
		long long ans=0;
		if(s<=(n+1)/2){
			for(int i=s;i<n-1;i++){
				ans+=w[i];
			}
			ans-=w[n-1];
			ans*=s;
			cout<<ans<<endl;
		}else{
			for(int i=s;i<n;i++){
				ans+=w[i];
			}
			ans*=s;
			cout<<ans<<endl;
		}
	}
	return 0;//PLEASE AC;
}
