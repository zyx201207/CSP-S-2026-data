#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;


struct node{
	ll n;
	ll pi=-1;
	ll d=0x3f3f3f3f;
	ll vis;
};

class cmp{
public:
	bool operator()(const node& o1,const node& o2){
		return o1.d>o2.d;
	}
};

signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	//cout<<"!\n";
	
	ll c,q;
	cin>>c>>q;
	//cout<<"!\n";
	
	
	for(ll t=0;t<q;t++){
		ll n,d;
		cin>>n>>d;
		vector<ll> x(n);
		vector<vector<ll> > to(n);
		vector<vector<ll> > w(n);
		vector<node> nodes(n);
		for(ll i=0;i<n;i++){
			cin>>x[i];
		}
		//cout<<"!\n";
		
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				ll wei=llabs(x[i]-x[j]);
				if(wei<=d){
					to[i].push_back(j);
					to[j].push_back(i);
					w[i].push_back(wei);
					w[j].push_back(wei);
				}	
			}
		}
		//cout<<"!\n";
		
		ll ans=0;
		
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(a==b)continue;
				priority_queue<node,vector<node>,cmp> pq;
				for(ll i=0;i<nodes.size();i++){
					nodes[i].d=0x3f3f3f3f;
					nodes[i].vis=0;
					nodes[i].pi=-1;
					nodes[i].n=i;
				}
				//cout<<"!\n";
				nodes[a].d=0;
				pq.push(nodes[a]);
				while(!pq.empty()){
					node st=pq.top();
					pq.pop();
					ll u=st.n;
					for(ll e=0;e<to[u].size();e++){
						if(to[u][e]!=0){
							if(st.d+w[u][e]<nodes[to[u][e]].d){
								nodes[to[u][e]].d=st.d+w[u][e];
								pq.push(nodes[to[u][e]]);
								nodes[e].pi=u;
							}
						}
					}
				}
				vector<int> p1;
				for(int p=b;p!=a;p=nodes[p].pi){
					p1.push_back(p);
				}
				
				//////////////////////////////////////////
				priority_queue<node,vector<node>,cmp> pq2;
				for(ll i=0;i<nodes.size();i++){
					nodes[i].d=0x3f3f3f3f;
					nodes[i].vis=0;
					nodes[i].pi=-1;
					nodes[i].n=i;
				}
				
				nodes[b].d=0;
				pq2.push(nodes[b]);
				while(!pq2.empty()){
					node st=pq2.top();
					pq2.pop();
					ll u=st.n;
					for(ll e=0;e<to[u].size();e++){
						if(to[u][e]!=0){
							if(st.d+w[u][e]<nodes[to[u][e]].d){
								nodes[to[u][e]].d=st.d+w[u][e];
								pq2.push(nodes[to[u][e]]);
								nodes[e].pi=u;
							}
						}
					}
				}
				vector<int> p2;
				for(int p=a;p!=b;p=nodes[p].pi){
					p2.push_back(p);
				}
				
				reverse(p1.begin(),p1.end());
				if(p1!=p2)ans++;
			}
		}
		cout<<ans<<'\n';
	}	
}