#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define F_up(x,y,z) for(int x=y;x<=z;x++)
#define F_down(x,y,z) for(int x=y;x>=z;x--)
#define F_in(x,y) for(auto x:y)
#define W(t) while(t--)
#define WALL while(1)
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[500005],t[500005];
int bel[500005];
vector<int> hv[500005];
int first[505];
int dis[1005][1005];
int diss[1005][1005];
//bool vis[1005][1005]; 
bool in_queue[1005][1005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	F_up(i,1,m){
		cin>>w[i];
	}int nl=0;
	F_up(i,1,n){
		cin>>k[i];
		F_up(j,1,k[i]){
			++nl;
			cin>>a[nl]>>t[nl];
			bel[nl]=i;
			if(j==1) first[i]=nl;
			hv[a[nl]].push_back(nl);
		}
	}memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(diss,0x3f3f3f3f,sizeof(diss));
	F_up(s,1,m){
//		cout<<s<<':'<<endl;
//		F_in(i,hv[s]){
//			cout<<i<<' ';
//		}cout<<endl;
		queue<int> q;
		F_in(i,hv[s]){
			q.push(i);
			in_queue[s][i]=1;
			dis[s][i]=t[i]+w[a[i]];
		}while(!q.empty()){
			int x=q.front();
//			cout<<"now"<<x<<endl;
			in_queue[s][x]=0;
			q.pop();
//			vis[s][bel[x]]=1;
			F_up(i,first[bel[x]],nl){
//				cout<<i<<'?'<<endl;
				if(bel[i]!=bel[x]) break;
//				cout<<"ok1"<<endl;
				if(i==x) continue;
//				cout<<"ok2"<<endl;
				if(dis[s][x]<dis[s][i]){
					dis[s][i]=dis[s][x];
//					cout<<"ok3"<<endl;
					if(!in_queue[s][i]){
						in_queue[s][i]=1;
						q.push(i);
//						cout<<"allok"<<endl;
//						cout<<x<<"->"<<i<<endl;
					}
				}
			}F_in(i,hv[a[x]]){
//				cout<<i<<'?'<<endl;
				if(dis[s][x]+t[x]+t[i]<dis[s][i]){
//					cout<<"ok1"<<endl;
					dis[s][i]=dis[s][x]+t[x]+t[i];
					if(!in_queue[s][i]){
						in_queue[s][i]=1;
						q.push(i);
//						cout<<"allok"<<endl;
//						cout<<x<<"->"<<i<<endl;
					}
				}
			}
		}F_up(i,1,nl){
			diss[s][a[i]]=min(diss[s][a[i]],dis[s][i]+t[i]+w[a[i]]);
		}
	}W(q){
		int s,to;
		cin>>s>>to;
		cout<<diss[s][to]<<endl;
	}return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(in_queue,0,sizeof(in_queue));
		F_in(i,hv[s]){
			q.push(i);
			dis[i]=w[a[i]]+t[i];
			in_queue[i]=1;
		}while(!q.empty()){
			int x=q.front();
			in_queue[x]=0;
			q.pop();
			F_up(i,first[bel[x]],nl){
				if(bel[i]!=bel[x]) break;
				if(dis[x]<dis[i]){
					dis[i]=dis[x];
					if(!in_queue[i]){
						in_queue[i]=1;
						q.push(i);
					}
				}
			}F_in(i,hv[a[x]]){
				if(dis[x]+t[x]+t[i]<dis[i]){
					dis[i]=dis[x]+t[x]+t[i];
					if(!in_queue[i]){
						in_queue[i]=1;
						q.push(i);
					}
				}
			} 
		}int ans=0x3f3f3f3f;
*/