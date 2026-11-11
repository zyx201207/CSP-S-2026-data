#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005];
struct MJ{
	ll cnt,sum,sun;
}mj[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int m,d;
		cin>>m>>d;
		int o;
		cin>>o;
		for(int i=2;i<=m;i++){
			int p;
			cin>>p;
			a[i]=p-o;
		}
	mj[1].sum=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(a[j]<=a[i]+d) mj[j].cnt++;
			if(mj[j].cnt=1) mj[j].sum=mj[i].sum+1;
			if(mj[j].cnt>1) {
				if(mj[j].sum==mj[i].sum+1){
					mj[j].sun++;
				}
			}
		}
	}
	ll wet=0;
	for(int i=1;i<=m;i++){
		if(mj[i].cnt>=2&&mj[i].sun==2)
			wet++;
			cout<<mj[i].cnt<<" "<<mj[i].sun<<endl;
	}
	cout<<wet<<endl;
}
	return 0;
}

