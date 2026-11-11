#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000001],zy[200001],zyh[200002];
deque<int> dq;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		memset(zyh,-1,sizeof(zyh));
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			while(!dq.empty()&&a[dq.front()]+d<a[i]) dq.pop_front();
			if(dq.empty()) zy[i]=-1;
			else zy[i]=dq.front(),zyh[dq.front()]=i;
			dq.push_back(i);
		}
		while(!dq.empty()){
			zyh[dq.back()]=n;
			dq.pop_back();
		}
		for(int i=1;i<=n;i++){
			if(zy[i+1]==-1) zyh[i]=-1;
		}
		zyh[n]=-1;
		for(int i=1;i<=n;i++){
			if(zyh[i]==-1) continue;
			for(int j=i+1;j<=n;j++){
				if(zy[j]==-1) break;
				int l=i,r=j;
				while(l<=r) l=zyh[l],r=zy[r];
				if(r-l==-1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
/*
tang bu tang
wo ba 30 hang de -1 xie cheng le 1
gen ju shu ju dian lai shuo gan jue shi tu lun
dan shi fei chang de bu xiang tu lun
<(O_O)>
*/