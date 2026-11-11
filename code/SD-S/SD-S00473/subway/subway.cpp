#include<bits/stdc++.h>
using namespace std;
vector<long long> a[1000005];
long long c,n,m,d,q,v,w,t,startt,endd,bj=0,gdw;
long long ww[1000005]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	bool vis[1000005]={0};
	for(long long i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>t;
		for(long long j=1;j<=t;j++){
			cin>>v>>w;
			if(i==1&&j==1){
				gdw=w;
			}
			if(gdw!=w){
				bj=1;
			}
			if(j!=v){
				a[j].push_back(v);
			}
		}
	}
	if(bj==0){
		for(long long i=1;i<=q;i++){
			cin>>startt>>endd;
			queue<long long >no;
			queue<long long >bs;
			no.push(startt);
			bs.push(0);
			memset(vis,0,sizeof(vis));
			while(!no.empty()){
				long long dq=no.front(),nbs=bs.front();
				if(dq==endd){
					cout<<ww[startt]+ww[endd]+nbs*gdw*2;
					break;
				}
				no.pop();
				bs.pop();
				for(long long i=0;i<a[dq].size();i++){
					if(!vis[a[dq][i]]){
						no.push(a[dq][i]);
						bs.push(nbs+1);
						vis[a[dq][i]]=1;
					}
				}
			}
		}
	}else{
		for(long long i=1;i<=q;i++){
			cin>>startt>>endd;
			cout<<2*(ww[startt]+ww[endd])<<endl;
		}
			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

