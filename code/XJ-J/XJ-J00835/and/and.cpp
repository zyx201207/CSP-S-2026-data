#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m,maxn=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(m==2){
		int t=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				if(t>maxn){
					maxn=t;
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}