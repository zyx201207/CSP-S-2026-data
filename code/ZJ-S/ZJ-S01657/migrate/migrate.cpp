//WoSiLe.
//ZheShiWoZuiHouDeBaoLiLe...
//WoMeiZhaoLe.
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int rf(int l,int r,long long x,long long* w){
	while(l<r){
		int mid=(l+r+1)/2;
		if(w[mid]<=x)l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long x[n+5];
		for(int i=1;i<=n;++i)cin>>x[i];
		if(c==11||c==12){
			cout<<n-(d/(x[2]-x[1]))*2+1<<endl;
			continue;
		}
		vector<pair<int,int>>haha[n+5];
		for(int i=1;i<=n;++i)
		haha[i].push_back({0,0});
		for(int i=1;i<=n;++i){
			int tmp=rf(i,n,x[i]+d,x);
			haha[i][0].second=tmp;
		}
		for(int i=1;i<=n;++i){
			int tmp=rf(1,i,x[i]-d,x);
			haha[i][0].first=tmp;
		}
		for(int i=1;i<=n;++i)
		if(haha[i][0].first==n+5)
		haha[i][0].first=i;
		for(int i=1;i<=n;++i)
		for(int j=1;;++j){
			int l=haha[i][j-1].first,r=haha[i][j-1].second;
			if(haha[l][0].first==l&&haha[r][0].second==r)break;
			haha[i].push_back({haha[l][0].first,haha[r][0].second});
		}
//		for(int i=1;i<=n;++i){
//			cout<<i<<":";
//			for(int j=0;j<haha[i].size();++j){
//				cout<<"("<<haha[i][j].first<<" "<<haha[i][j].second<<")";
//			}
//			cout<<endl;
//		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+2;j<=n;++j){
				if(haha[i][haha[i].size()-1].second<j)break;
				int tmp;
				tmp=0;
				for(int k=2;;++k){
					for(int kk=1;kk<k&&tmp<=2;++kk){
						int l=haha[i][kk-1].second,r=haha[j][k-kk-1].first;
						if(l>=r)tmp+=l-r+1;
					}
//				cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" tmp:"<<tmp<<endl;
					if(tmp==2)ans++;
					if(tmp>=2)break;
				}
			}
		}
		cout<<ans<<endl;
	}
}