#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long cnt=0,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((a[j]&a[j+1])>cnt){
				cnt=a[j]&a[j+1];
			}
		}
	}
	cout<<cnt;
}
