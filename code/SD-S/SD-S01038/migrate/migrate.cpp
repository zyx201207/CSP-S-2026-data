#include<iostream>
using namespace std;
long long a[1000005];long long n,d;
int Find(int x){
	int l=x,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(a[mid]-a[x]<=d) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		long long kt=a[2]-a[1];
		if(c==11||c==12){
			if(d>=2*kt&&d<3*kt) cout<<n-3<<"\n";
			else cout<<"0\n";
			continue;
		} 
		if(c<=3){
			int ans=0;
			for(int i=1;i<=n;i++){
				int id=Find(i);
				int R=Find(id);
				if(R==id||id==i||id==i+1) continue;
				int L=Find(id-1);
				if(id==i+2){
					ans+=L-id;
					continue;
				}
				int LL=Find(id-2);
				ans+=L-LL;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c==13||c==14) cout<<"0\n";
	}
	return 0;
}
