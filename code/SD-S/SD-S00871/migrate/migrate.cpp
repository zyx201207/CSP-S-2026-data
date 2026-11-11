#include<bits/stdc++.h>
using namespace std;

const int N=2e6;
long long c,t,n,d,x[N+5];
vector <long long> v1,v2;
bool szz(long long u,long long v){
	long long uu=u;
	long long vv=u;
	while(uu<v){
		for(int i=uu;i<=v;i++){
			if(x[i]-x[uu]<=d){
				uu=i;
			}
			else break;
		}
		v1.push_back(uu);
	}
	while(vv>u){
		for(int i=vv;i>=u;i--){
			if(x[vv]-x[i]<=d){
				vv=i;
			}
			else break;
		}
		v2.push_back(vv);
	}
	if(v1.size()!=v2.size()) return 0;
	for(int i=0;i<v1.size();i++){
		long long r=v1.size()-1-i;
		if(v1[i]!=v1[r]){
			return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool P=true;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1) cout<<0<<endl;
		long long cnt=x[2]-x[1];
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=cnt) P=false;
		}
		if(P==true){
			long long ans=0;
			long long t1=d/cnt;
			long long r=1;
			x[n+1]=1e18+5;
			x[0]=1e18;
			for(int i=1;i<=n;i++){
				if(x[i+1]-x[i]>d){
					//cout<<"BETTY "<<r<<' '<<i<<endl;
					for(int u=r;u<=i;u++){
						for(int v=u+1;v<=i;v++){
							if((v-u)>=t1&&(v-u)%t1!=0){
								ans++;
							}
						}
					}
					r=i+1;
				}
			}
			cout<<ans<<endl;
		}
		else{
			x[n+1]=1e18+5;
			x[0]=1e18;
			long long r=1;
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(x[i+1]-x[i]>d){
					for(int u=r;u<=i;u++){
						for(int v=u+1;v<=i;v++){
							if(szz(u,v)==1){
								ans++;
							}
							v1.clear();
							v2.clear();
						}
					}
					r=i+1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
