#include<bits/stdc++.h>
#define endl '/n'
using namespace std;
const int Q=3e5+5;
using namespace std;
long long a[Q];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	long long maxx2=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				maxx2=max(maxx2,x);
			}
		}
		cout<<maxx2;	
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

