#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long now=a[1];
	for(int i=2;i<=n;i++){
		if((now+m)/(i-1)<a[i]){
			cout<<i-1;
			return 0;
		}
		else now+=a[i];
	}
	cout<<n;
	return 0;
}
