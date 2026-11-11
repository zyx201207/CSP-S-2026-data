#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],aj[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		aj[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		long long cnt=0,andd=0;
		bool cmp=true;
		for(int j=i;j<n;j++){
			andd+=aj[j];
			cnt++;
			if(abs(andd)>m){
				ans=max(ans,cnt);
				cmp=false;
				break;
			}
		}
		if(cmp){
			cout<<n-i+1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
