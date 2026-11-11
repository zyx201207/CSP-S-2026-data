#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000086],minn;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long x=m,c=1;
		for(int j=1;j<=n;j++){
			if(x>=abs(a[i]-a[j])&&i!=j){
				x-=abs(a[i]-a[j]);
				c++;
			}
		}
		minn=max(minn,c);
	}
	cout<<minn;
	return 0;
}
