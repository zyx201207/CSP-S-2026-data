#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long pri[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,
16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
struct nod{
	long long val;
	vector<int>vis;
};
nod a[200005];
vector<int> sep(long long n){
	int lexp=30;
	vector<int>res;
	while(n>=0){
		if(n==0) break;
		for(int i=lexp;i>=0;i--){
			if(pri[i]<=n){
				lexp=i;
				n-=pri[i];
				res.push_back(lexp);
				break;
			}
		}
	}
	return res;
}
bool comp(vector<int> a,vector<int> b){
	if(a.size()!=b.size()) return a.size()>b.size();
	if(a.size()==b.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]>b[i]) return 1;
		}
	}
	return 0;
}
bool cmp(nod a,nod b){
	return comp(a.vis,b.vis);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans; 
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].val);
		a[i].vis=sep(a[i].val);
	}
	sort(a,a+n,cmp);
	ans=a[0].val;
	for(int i=1;i<m;i++){
		ans=(ans & a[i].val);
	}
	printf("%d",ans); 
	return 0;
} 
