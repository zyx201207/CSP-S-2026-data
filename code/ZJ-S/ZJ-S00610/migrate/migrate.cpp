#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d,a[2000010],f,b[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		f=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
				f=1;
			if(a[i]-a[i-1]>d)
				b[i]=0;
			else
				b[i]=1;
		}
		if(a[n]-a[1]<=d){
			cout<<"0\n";
			continue;
		}
		if(f==0){
			long long l=d/(a[2]-a[1]);
			if(l<=1||(n<l+l-1))
				cout<<0<<'\n';
			else
				cout<<n-(l+l-1)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			long long l=a[i+1],w=1,lw=0,fl=1;
			for(int j=i+1;j<=n;j++){
				if(b[j]==0)
					break;
				cout<<w<<" "<<lw<<" "<<l<<" "<<a[j]<<" "<<fl<<endl;
				if(a[j]>=l)
					l=l+d,lw=w,w=i-1;
				if(lw<1)
					continue;
				if(a[lw-1]+d>=a[j]){
					fl++;
					if(a[lw-2]+d>=a[j])
						fl++;
				}
				if(fl>2)
					break;
				if(fl==2)
					ans++;
			}
			cout<<"\n";
		}
		cout<<ans<<'\n';
	}
	return 0;
}