#include<bits/stdc++.h>
using namespace std;
const int N=5010;
struct P{
	long long x,res;
};
long long a[N],tmp[N],cnt=0,tmps[N];
P res[N*N];
void solve(){
	long long n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp[i]=1;
		tmps[i]=1e18;
	}
	tmps[n+1]=1e18;
	cnt=0;
	sort(a+1,a+1+n);
	for(int s=3;s<=n;s++){
		tmp[s]=tmp[s-1];
		for(int j=1;j<s-1;j++){
			for(int i=1;i<j;i++){
				long long k=j+1;
				if(a[s]-a[i]<=d){
					continue;
				}
				if(a[j]-a[i]>d||a[k]-a[i]>d||a[s]-a[k]>d||a[s]-a[j]>d){
					continue;
				}
				if((j!=i+1&&a[s]-a[j-1]<=d)||(s!=j+2&&a[k+1]-a[i]<=d)){
					continue;
				}
				if((a[i]-a[i-1]<=d)&&(a[i+1]-a[i-1]>d)){
					ans+=i-tmp[i]+1;
				}else{
					ans+=1;
				}
				tmp[s]=s;
				tmps[i]=i;
			} 
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}/*
1 1
10 3
0 3 6 7 8 9 10 11 14 17

ans:2
*/
