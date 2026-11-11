#include <bits/stdc++.h>
using namespace std;
int n,m,a[50007],b[50007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0;
	sort(a,a+n);
	int minn=a[1]-a[0],min_star=0;
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]<minn){
			minn=b[i];
			min_star=i;
		}
	}
	int cu=min_star+1,cnt=1;
	while(m>=a[cu]-a[min_star]*cnt){
		if (cu==n-1){
			break;
		}
		m-=(a[cu]-a[min_star])*cnt;
		a[min_star]=a[cu];
		cnt++;
		cu++;
		min_star++;
		ans++;
	}
	cout << ans << endl;;
	return 0;
}
