#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mxk=0,k,z;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=1;i<=n-1;i++){
		k=1,z=m;
		for(int j=i+1;j<=n;j++){
			if(a[i]-a[j]<=z&&j!=n){
				k++;
				z-=(a[i]-a[j]);
			}else if(a[i]-a[j]<=z&&j==n){
				k++;
				z-=(a[i]-a[j]);
				mxk=max(mxk,k);
				break;
			}else{
				mxk=max(mxk,k);
				break;
			}
		}
	}
	cout<<mxk<<endl;
} 