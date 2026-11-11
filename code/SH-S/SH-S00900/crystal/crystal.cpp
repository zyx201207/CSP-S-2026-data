#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long times(long long b[]){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt=max(cnt,(upper_bound(b,b+1+n,b[i])-lower_bound(b,b+1+n,b[i])));
	}
	return cnt;
}
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	long long ans=times(a);
	a[1]+=1;
	while(m--){
		sort(a,a+1+n);
		ans=max(ans,times(a));
		a[1]+=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
