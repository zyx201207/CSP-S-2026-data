#include<bits/stdc++.h>
using namespace std;
long long a[200222],b[200222],ans;
int n,m;
bool cmp(long long x,long long y){
	return x<y;
}
long long calc(long long x){
	long long i=0,d=x;
	while(d){
		if(x&1==1){
			if(d==pow(2,i)){
				return pow(2,i);
			}
			d-=pow(2,i);
		}
		x=x>>1;
		i++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=ans^a[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=m;i++){
		ans=(ans^b[i])%calc(ans<<1);
	}
	cout<<ans;
	return 0;
}

