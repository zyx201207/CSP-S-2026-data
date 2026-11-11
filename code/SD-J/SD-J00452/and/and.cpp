#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=200005;
long long a[N];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j]>=ans&&i!=j){
				ans=a[i]&a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
