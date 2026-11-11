#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,m,b[maxn];
struct Edge{
	ll z,jl;
}a[maxn];
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		a[i].jl=a[i].z-a[i-1].z;
	}
	ll ans,mn=1e18,jll;
	for(int i=2;i<=n;i++){
		if(abs(a[i].jl-a[i-1].jl)<mn){
			mn=abs(a[i].jl-a[i-1].jl);
			jll=i;
		}
	}
	jll+=1;
	ll cnt=0;
	for(int i=jll;i>=1;i--){
		if(m>a[i].jl){
			m-=a[i].jl;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 