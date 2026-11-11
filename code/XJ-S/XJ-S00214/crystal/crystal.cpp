#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	long long t=m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);

	long long maxc=-10000000000000;
	for(int i=2;i<=n;i++){
		
		long long cnt=1;
		m=t;
		
		for(int j=i-1;j>=1;j--){
			if(m-(a[i]-a[j])>=0){
				m-=(a[i]-a[j]);
				cnt++;
				maxc=max(maxc,cnt);
			}
		}
	}
	
	cout<<maxc;
	return 0;
}
