#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+9;
long long a[mx];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	for(int i=n-1,j=n-1,sum=a[n-1];i>=0;i--){
		while(j>0&&sum+a[j-1]+m>=(i-j+2)*a[i]){
			//clog<<j<<" "<<sum<<" "<<a[i]<<"\n";
			sum+=a[j-1];
			j--;
		}
		//clog<<j<<" "<<sum<<" "<<a[i]<<"\n\n";
		ans=max(ans,i-j+1);
		sum-=a[i];
	}
	cout<<ans;
	return 0;
}//Liu Boyan
