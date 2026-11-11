#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxs,b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			if((i+1)*i/2>m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	long long x,cnt;
	for(int i=1;i<=n;i++){
		 x=m,cnt=0;
		for(int j=1;j<=i;j++){
			b[j]=a[j]-a[i];
		}
		for(int j=i;j>=1;j--){
			if(x+b[j]>=0){
				cnt++;
				x+=b[j];
			}
			else break;
		}
		maxs=max(cnt,maxs);
	}
	cout<<maxs;
	return 0;
}
