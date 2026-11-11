#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005],b[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]&a[j]>maxn)
				maxn=(a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
