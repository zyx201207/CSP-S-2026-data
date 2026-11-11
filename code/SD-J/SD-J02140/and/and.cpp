#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[n+1],mx=1111111111;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m>0){
		int p=0,wz;
		for(int i=1;i<=n;i++){
			if(a[i]>=p){
				p=a[i];
				wz=i;
			}
		}
		mx=mx & a[wz];
		a[wz]=0;
		m--;
	}
	cout<<mx;
	return 0;
}
