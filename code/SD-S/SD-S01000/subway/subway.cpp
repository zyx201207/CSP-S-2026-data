#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sunway.out","w",stdout);
	long long c,n,m,d,q,k,r1,r2;
	cin>>c>>n>>m>>d>>q;
	long long dtx[n+1][m],dtz[m+1],fz[m+1];
	for(long long i=1;i<=m;i++){
		cin>>dtz[i];
	}
	for(long long i=0;i<n;i++){
		cin>>k;
		for(long long l=1;l<=k;l++) cin>>dtx[i][l];
		dtx[i][0]=k;
	}
	for(int qewo=0;qewo<2;qewo++){
		cin>>r1>>r2;
		long long time=dtz[r1]+dtz[r2];
		queue<int> q;
		q.push(r1);
		while(!q.empty()){
			long long dq;
			dq=q.front();
			q.pop();
			for(long long vva=0;vva<n;vva++){
				for(long long aicy=2;aicy<=k;aicy+=2){
					if(dtx[vva][aicy]==dq){
						for(long long ai=2;ai<=k;ai+=2){
							if(ai!=aicy and fz[dtx[vva][ai]]==0){
								fz[dtx[vva][ai]]=dtx[vva][ai-1]+dtx[vva][aicy-1];
								q.push(fz[dtx[vva][ai]]);
							}
						}
					}
				}
			}
		}
		cout<<fz[r2];
	}
	return 0;
}
