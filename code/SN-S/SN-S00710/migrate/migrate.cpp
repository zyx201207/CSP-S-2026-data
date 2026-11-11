#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace zhu{bool ST;
int c,T,n,d,cnt[5050],dis[5050],q[5050],l,r,tong[5050],a[2002000];
set<int> st;
bool ED;string main(){
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c>=11&&c<=12){
			int o=a[2]-a[1];
			if((d/o)<=1||n<d/o*2){
				cout<<0<<"\n";
				continue;
			}
//			cout<<n<<" "<<d/o<<"\n";
			cout<<n-d/o*2+1<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++) tong[j]=0;
			dis[i]=0;cnt[i]=1;
			st.clear();
			l=1,r=0;
			q[++r]=i;
			tong[0]++;
			st.insert(0);
			for(int j=i+1;j<=n;j++){
//				cerr<<j<<" ";
				while(l<=r&&a[q[l]]<a[j]-d){
//					cerr<<q[l]<<"\n";
//					cout<<j<<" erase "<<l<<" "<<q[l]<<"\n";
					tong[dis[q[l]]]-=cnt[q[l]];
					if(!tong[dis[q[l]]]) st.erase(dis[q[l]]);
					l++;
				}
				dis[j]=*st.begin()+1;
				cnt[j]=tong[dis[j]-1];
				if(!tong[dis[j]]) st.insert({dis[j]});
				tong[dis[j]]+=cnt[j];
////				cout<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
				q[++r]=j;
				if(cnt[j]==2){
//					cout<<i<<" "<<j<<"\n"; 
					ans++;
				}
			}
//			exit(0);
		} 
		cout<<ans<<'\n';
	}
	return ".";
}
}
signed main(){
//	system("fc migrate.out migrate4.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<(&zhu::ST-&zhu::ED)/1048576.0;
}
/*
0 1
10 3
1 2 3 4 5 6 7 8 9 10
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace zhu{bool ST;
int c,T,n,d,a[200200],f[200200],g[200200],sum[200200];
vector<int> ve[200200];
multiset<pair<int,int>> st;
bool ED;string main(){
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			st.insert({a[i],i});
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			auto t=st.lower_bound({a[i]-d,0});
			int j=t->second,tmp=0;
//			cout<<i<<" *** "<<j<<"\n";
			if(j<i){
				t=st.lower_bound({a[j]-d,0});
				int L=t->second;
				t=st.lower_bound({a[j+1]-d,0});
//				cout<<i<<" --- "<<L<<" "<<(t->second)-1<<'\n';
				if(t==st.begin()) f[i]=i-j+1;
				else{
					t--;
					int R=t->second;
//					cout<<i<<" --- "<<L<<" "<<R<<"\n";
					if(L<=R) f[i]=sum[R]-sum[L-1]+(i-j+1),tmp=sum[R]-sum[L-1];
					else     f[i]=i-j+1;
				}
			} 
			else f[i]=i-j+1;
			g[i]=g[i-1];
			for(auto v:ve[i]) g[i]+=v;
//			cout<<i<<" "<<f[i]<<" "<<g[i]<<"\n";
			sum[i]=sum[i-1]+f[i];
			ans+=g[i];
			
			t=st.lower_bound({a[i]+d,0});
			j=t->second;
			if(j<=i+1) continue;
			
			int w=tmp+1;
			t=st.lower_bound({a[i]-d,0});
			int L=t->second;
			t=st.lower_bound({a[j-1]-d,0});
			if(t!=st.begin()){
				t--;
				int R=t->second;
				if(L<=R) w+=sum[R]-sum[L-1];
			}
//			cout<<i<<" waw "<<w<<"\n";
			
			t=st.upper_bound({a[j-2]+d,1e18});
			if(t==st.end()) continue;
			ve[t->second].push_back(w);
			t=st.upper_bound({a[j-1]+d,1e18});
			if(t==st.end()) continue;
			ve[t->second].push_back(-w);
		}
		cout<<ans<<"\n";
		st.clear();
		for(int i=1;i<=n;i++) f[i]=g[i]=0,ve[i].clear();
	}
	return ".";
}
}
signed main(){
//	freopen("migrate3.in","r",stdin);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<(&zhu::ST-&zhu::ED)/1048576.0;
}
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
