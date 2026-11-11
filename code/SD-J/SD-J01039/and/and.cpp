#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200005;
long long a[N];
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=i;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long g=a[2];
		for(int i=3;i<=n;g++){
			g=(g&a[i]);
		}
		ans=max(ans,g);
		for(int i=1;i<n;i++){
			long long num=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i) num=(num&a[j]);
				else continue;
			}
			ans=max(ans,num);
		}
		return 0;
	}
	return 0; 
}
