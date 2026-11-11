#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
    long long sum=a[1];
    for(int i=2;i<=m;i++){
        sum&=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
