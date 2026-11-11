#include <bits/stdc++.h>
#define N 2000010
#define int long long
using namespace std;
struct node{
    int n,w;
};
struct pq{
	vector<node> c;
	node top(){
		return c[0];
	}
	bool empty(){
		if(c.size()==0){
			return 1;
		}
		return 0;
	}
	void push(node x){
		c.push_back(x);
		int j=c.size()-1;
		while(j!=0){
			if(c[j].w>c[(j-1)/2].w){
				swap(c[j],c[(j-1)/2]);
			}
			j=(j-1)/2;
		}
	}
	void pop(){
		swap(c[0],c[c.size()-1]);
		c.pop_back();
		signed j=0;
		while(c.size()>j*2+1){
			if(c.size()==j*2){
				if(c[j].w<c[j*2+1].w){
					swap(c[j],c[j*2+1]);
				}
				return;
			}
			if(c[j*2+1].w>=c[j*2+2].w){
				if(c[j].w<c[j*2+1].w){
					swap(c[j],c[j*2+1]);
				}
				j=j*2+1;
			}else{
				if(c[j].w<c[j*2+2].w){
					swap(c[j],c[j*2+2]);
				}
				j=j*2+2;
			}
		}
	}
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        int x[N];
        cin>>n>>d;
        vector<int> g[N];
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=i-1;j>=1;j--){
                if(x[i]-x[j]>d){
                    break;
                }
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
			int ljs[N]={};
			int dist[N];
			memset(dist,0x3f3f3f3f3f3f3f3f,sizeof(dist));
            pq q;
            q.push({i,0});
            dist[i]=0;
            while(!q.empty()){
                node nw=q.top();
                q.pop();
                for(int k:g[nw.n]){
                    if(dist[k]==nw.w+1){
                        ljs[k]++;
                        if(ljs[k]==2){
                            ans++;
                        }else if(ljs[k]==3){
                            ans--;
                        }
                    }else if(dist[k]>nw.w+1){
                        dist[k]=nw.w+1;
                        q.push({k,dist[k]});
                        if(ljs[k]==2){
                            ans--;
                        }
                        ljs[k]=1;
                    }
                }
            }
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
