#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=abs(a[2]-a[1]),y=1,sum=0;
	for(long long i=1;i<n;i++){
		sum+=x*y;
		y++;
	}
	for(long long i=sum;i>=x;i-=x*y,y--){
		if(m>=i){
			cout<<y;
			return 0;
		}
	}
	cout<<1;
	return 0;
} 
