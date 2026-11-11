#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=0,r=n+1,cntl=0,cntr=0;
	long long ans=0;
	while(l<r){
		//cout << l << " " << r << endl;
		if(cntl<=cntr){
			if(c[l]!=c[r]){
				ans+=cntl;			
			}
			cntr-=cntl;
			cntl=0;
		}
		else if(cntl>cntr){
			if(c[l]!=c[r]){
				ans+=cntr;
			}
			cntl-=cntr;
			cntr=0;
		}
		if(cntl==0){
			l++;
			if(l==r)break;
			cntl=a[l];
		}
		if(cntr==0){
			r--;
			if(l==r)break;
			cntr=a[r];
		}
	}
	cout << ans << endl;
}