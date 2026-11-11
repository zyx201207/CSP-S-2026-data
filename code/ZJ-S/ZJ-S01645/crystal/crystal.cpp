#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],m0,s0=0,i0,s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
		b[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		m0=m,i0=i-1;
		while(m0-b[i0]>=0&&i0>=1){
			m0-=b[i0];
			s0++;
			i0--;
		}
		s=max(s,s0);
		s0=1;
	}
	cout<<s;
	return 0;
} 
