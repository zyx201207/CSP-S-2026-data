#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
int wei[N][31];
int bit2s[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int a[N];
void chai(int pos,int x){
	for(int i=0;i<=30;i++){
		if(x>>i&1){
			wei[pos][i]=1;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	int maxl=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxl=max(maxl,a[i]);
		chai(i,a[i]);
	}
	int point;
	for(int i=0;i<=30;i++){
		if(bit2s[i]>maxl){
			point=i;
			break;
		} 
	}
	int ans=0;
	int chance=n-m;
	set<int> checkpos;
	for(int i=point;i>=0;i--){
		int orichance=chance;
		vector<int> temp;
		temp.clear();
		for(int j=1;j<=n;j++){
			if(checkpos.find(j)!=checkpos.end()) continue;
			if(wei[j][i]==0){
				temp.push_back(j);
				chance--;
			} 
		}
		if(chance<0){
			chance=orichance;
		} 
		else{
			ans+=1<<i;
			for(auto j:temp){
				checkpos.insert(j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
