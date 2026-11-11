#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

long long a[N],c[N];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	
	long long ans=0, now=0;
	int l=1,r=1;//右扩到x>m，减cl到r的前缀和a[r]-a[l-1] 
	while(r<n){
		if(now<=m){
			r++;
			now+=(r-l)*c[r];
		}
		while(now>m){
			l++;
			now-=a[r]-a[l-1];
//			printf("l:%d\n",l);
		}
//		printf("l:%d r:%d now:%d\n",l,r,now);
		ans=max(ans,(long long)r-l+1);
	}
	cout << ans;
	
	return 0;
} 
