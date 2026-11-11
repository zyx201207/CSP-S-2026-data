#include<bits/stdc++.h>
using namespace std;
long long n,m,r,now,ans,a[500010]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long l=1;l<=n;l++){
		now-=a[r]-a[l-1];
		r=max(r,l);
		while(r<n&&now+(r-l+1)*(a[r+1]-a[r])<=m){
			now+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
/*[(^v^)]*/
