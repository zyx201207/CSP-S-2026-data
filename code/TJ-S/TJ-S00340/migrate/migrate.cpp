#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using xll=__int128;
const ll mxn=2e6+7;
ll di[mxn],n,d;
namespace C1{
	int lstrong[mxn],rstrong[mxn];
	int ltoend[mxn],rtoend[mxn];
	ll llk[mxn],rlk[mxn];
	deque<int> gqu;
	void run(){
		gqu.clear();
		for(int i=0;i<=n;i++){
			ltoend[i]=rtoend[i]=0;
		}
		for(int i=1;i<=n;i++){
			while(!gqu.empty()&&di[gqu.front()]+d<di[i]){
				gqu.pop_front();
			}
			if(!gqu.empty()){
				// cout<<di[gqu.front()]<<di[i]<<"from\n";
				lstrong[i]=gqu.front();
			}else lstrong[i]=i;
			ltoend[lstrong[i]]++;
			gqu.push_back(i);
			// cout<<lstrong[i]<<endl;
		}
		gqu.clear();
		for(int i=n;i>=1;i--){
			while(!gqu.empty()&&di[gqu.front()]-d>di[i]){
				gqu.pop_front();
			}
			if(!gqu.empty()) rstrong[i]=gqu.front();
			else rstrong[i]=i;
			rtoend[rstrong[i]]++;
			gqu.push_back(i);
		}
		for(int i=1;i<=n;i++){
			if(rstrong[i]!=i) llk[i]=1;
			else llk[i]=0;
			if(rstrong[lstrong[i]]==i&&lstrong[i]!=i){
				llk[i]+=llk[lstrong[i]]-1;
			}
			if(rtoend[i]!=0){
				llk[i]+=rtoend[i];	
			}
			// cout<<rtoend[i]<<":"<<llk[i]<<" ";
		}
		// cout<<endl;
		for(int i=n;i>=1;i--){
			if(lstrong[i]!=i) rlk[i]=1;
			else rlk[i]=0;
			if(lstrong[rstrong[i]]==i&&rstrong[i]!=i){
				rlk[i]+=rlk[rstrong[i]]-1;
			}
			if(ltoend[i]!=0){
				rlk[i]+=ltoend[i];	
			}
			// cout<<rtoend[i]<<":"<<rlk[i]<<" ";
		}
		// cout<<endl;
		// for(int i=1;i<=n;i++){
		// }
		// for(int i=n;i>=1;i--){
		// }
		ll ans=0;
		for(int i=1;i<n;i++){
			// cout<<i<<" "<<llk[i]<<" "<<llk[i+1]<<" "<<rlk[i]<<" "<<rlk[i+1]<<endl;
			if(llk[i+1]>0&&rlk[i]>0){
				ans+=ll(llk[i+1]-1)*(rlk[i]-1);
			}
			// cout<<i<<endl;
			// cout<<rstrong[i]<<endl;
			// int rid=rstrong[rstrong[i]];
			// cout<<rid<<endl;
			// if(rstrong[i]==i||rid==rstrong[i]) continue;
			// if(lstrong[rid]==rid||i==lstrong[rid]) continue;
			// if(lstrong[lstrong[rid]]==i){
			// 	if(rstrong[i]!=lstrong[rid]&&rstrong[i]==lstrong[rid]+1){
			// 		ans+=(ll)llk[i]*rlk[rid];
			// 	}
			// }

		}
		cout<<ans<<"\n";
		// cout<<0<<endl;
	}
};
namespace C2{
	void run(){
		ll dir=di[2]-di[1];
		if(n<=3) cout<<0<<"\n";
		else{
			if(2*dir>d) cout<<0<<"\n";
			else{
				if(3*dir>d){
					ll b=d/dir;
					cout<<dir<<(n-2*b+1)<<"\n";
				}else{
					cout<<0<<"\n";
				}
			}
		}
	}
}
int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>di[i];
		}
		if(11<=c&&c<=12) C2::run();
		else C1::run();
	}
	return 0;
}