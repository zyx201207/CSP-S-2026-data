#include<bits/stdc++.h>
#define ll long long
#define VI vector<int>
#define endl '\n'
#define up(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
const int NN=2e6+5;
ll c,t,n,d,ans,minl;
ll x[NN],pre[NN];
map<array<int,2>,int> mp,lmp;
ll least_way(int l,int r){
	if(l==r) return 0;
	if(lmp[{l,r}]!=0) return lmp[{l,r}];
	int to=r;
	up(i,l+1,r+1) if(x[i]>x[l]+d){
		to=i-1;
//		cout<<l<<" to "<<to<<" to "<<r<<endl;
		break;
	}
	ll rt=1+least_way(to,r);
	lmp[{l,r}]=rt;
	return rt;
}
int count_way(int l,int r,int len){
	if(len>minl) return 0;
	if(l==r) return 1;
	if(mp[{l,r}]!=0) return mp[{l,r}];
	ll rt=0;
	up(i,l+1,r) if(x[i]<=x[l]+d) rt+=count_way(i,r,len+1);
	mp[{l,r}]=rt;
	return rt;
}
bool judge2way(int l,int r){
	ll rt=1,lstl=l;
	up(i,l+1,r-1){
		if(x[i+1]-x[i-1]>d){
//			cout<<"分割为"<<lstl<<"到"<<i<<endl;
			minl=least_way(lstl,i);
			ll way=count_way(lstl,i,0);
			rt*=way;
//			cout<<"累计道路条数"<<rt<<endl;
			if(rt>2) return 0;
		}
	}
//	cout<<"分割为"<<lstl<<"到"<<r<<endl;
	minl=least_way(lstl,r);
	rt*=count_way(lstl,r,0);
//	cout<<"累计道路条数"<<rt<<endl;
	return (rt==2);
}
int find2way(int l,int r){
	if(r-l<=2) return 0;
	ll rt=0;
	up(i,l,r){
		up(j,i+2,r){
//			cout<<"判断"<<i<<" to "<<j<<"路径数是否为2"<<endl;
			rt+=judge2way(i,j);
		}
	}
	return rt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		up(i,1,n) cin>>x[i];
		if(c<3){
			lmp.clear(); mp.clear(); ans=0;
			int l=1;
			up(i,2,n){
				if(x[i]-x[i-1]>d){
					ans+=find2way(l,i-1);
	//				cout<<"从 "<<l<<" 到 "<<i-1<<" 联通"<<endl;
					l=i;
				}
			}
			ans+=find2way(l,n);
	//		cout<<"从 "<<l<<" 到 "<<n<<" 联通"<<endl;
			cout<<ans<<endl;
		}else if(11<=c&&c<=12){
			ll gap=x[2]-x[1];
			if(2*gap>d||d>=gap*(n-1)) cout<<0<<endl;
			else cout<<max((ll)0,n-((d/gap)*2-1))<<endl;
		}
	}
	return 0;
}
