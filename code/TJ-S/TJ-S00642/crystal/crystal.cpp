#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int N;
long long M;
long long aa[MAXN];
long long aas[MAXN];
bool check(int a,int b){
	long long sum=aas[a]-aas[b-1];
	if(aa[a]*(a-b+1)-sum<=M){
		return true;
	}else return false;
}
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>aa[i];
	}
	sort(aa+1,aa+N+1);
	for(int i=1;i<=N;i++) aas[i]=aas[i-1]+aa[i];
	for(int i=1;i<=N;i++){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(i,mid)){
				r=mid-1;
				res=mid;
			}else{
				l=mid+1;
			}
		}
		ans=std::max(ans,i-res+1);
	}
	cout<<ans;
	
	
	
	return 0; 
}
