#include <bits/stdc++.h>
using namespace std;
long long a[1001000],n,m,cnt=-10000;;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
	}
	cout<<cnt;
	return 0;
}		
