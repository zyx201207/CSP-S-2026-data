#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+27;
const long long NEG=-10000000000027;

long long n,m;
long long ans=0;
long long a[MAXN],b[MAXN];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	long long l,r;
	long long sum=0,ans=0;
	for(l=1,r=2;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		if(sum<=m) ans=max(ans,r-l);
		else{
			while(sum>m) sum-=(a[r]-a[l++]);
		}
	}
	
	cout<<ans+1<<endl;
	
	return 0;
}