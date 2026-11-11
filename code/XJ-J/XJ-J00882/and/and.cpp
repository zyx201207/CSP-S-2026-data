#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],l,r,maxx=INT_MIN,o;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,r=m;
	for(int i=1;i<=n;i++){
		o=a[l];
		if(r<=n){
			for(int j=l+1;j<=r;j++){
				o=o and a[j];
			}
		}
		else{
			for(int j=l+1;j<=n;j++){
				o=o and a[j];
			}
			for(int j=1;j<=r;j++){
				o=o and a[j];
			}
		}
		maxx=max(maxx,o);
		l++;
		r++;
		if(r>n){
			r=r-n;
		}
	}
	cout<<maxx;
	return 0;
}