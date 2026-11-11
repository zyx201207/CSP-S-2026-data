#include<bits/stdc++.h>
using namespace std;
long long n,ans,sum,a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long i=1,j=sum,dt,l1=1,l2=n,mid=(sum+1)>>1;
	while(i<mid&&j>mid){
		dt=min(a[l1],a[l2]);
		dt=min(dt,mid-i+1);
		i+=dt,j-=dt;
		if(c[l1]!=c[l2])ans+=dt;
		a[l1]-=dt,a[l2]-=dt;
		if(!a[l1])l1++;
		if(!a[l2])l2--;
	}
	cout<<ans;
	return 0;
} 
