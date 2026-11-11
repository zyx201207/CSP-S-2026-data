#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int w[N];
int lu[N];
bool pd[N];
vector<int>zp[N];
vector<int>sl[N]; 
int a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i1=1;i1<=n;i1++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
		for(int j=1;j<i;j++){
			zp[a[i]].push_back(a[j]);
			sl[a[i]].push_back(t[i]+t[j]);
			zp[a[j]].push_back(a[i]);
			sl[a[j]].push_back(t[i]+t[j]);
		}
		}
	}
	while(q--){
		memset(pd,0,sizeof(pd));
		memset(lu,0x3f,sizeof(lu));
	long long cou=0;
		int x,y;
		cin>>x>>y;
		cou+=w[x];
		cou+=w[y];
		queue<int>lyl;
		lyl.push(x);
		lu[x]=0;
		while(!lyl.empty()){
			int s=lyl.front();
			lyl.pop();
			for(int i=0;i<zp[s].size();i++){
			int kn=zp[s][i];
			int cd=sl[s][i];
			lu[kn]=min(lu[kn],lu[s]+cd);

			if(pd[kn]==0){
				lyl.push(kn);
				pd[kn]=1;
			}
			}
		}
			memset(pd,0,sizeof(pd));
			lyl.push(x);
		while(!lyl.empty()){
			int s=lyl.front();
			lyl.pop();
			for(int i=0;i<zp[s].size();i++){
			int kn=zp[s][i];
			int cd=sl[s][i];
			lu[kn]=min(lu[kn],lu[s]+cd);
			if(pd[kn]==0){
				lyl.push(kn);
				pd[kn]=1;
			}
			}
		}
		
		cou+=lu[y];
		cout<<cou<<endl;
	}

}
  
