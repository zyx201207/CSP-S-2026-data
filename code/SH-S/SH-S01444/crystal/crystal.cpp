#include<bits/stdc++.h>
using namespace std;
bool dc=true;
long long fc,n,m,a[500020],maxn=1,cu,cnt=0;
int main(){
	freopen("crystalt.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(fc==0){
			fc=a[i];
		}
		if(a[i]-a[i-1]!=fc){
			dc=false;
		}
	}
	if(dc){
		cout<<sqrt(2*m/fc)+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		cu=m;cnt=1;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]<=cu){
				cu-=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
