#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e6;
long long n,m,a[maxn],ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	if(a[2]-a[1]==a[3]-a[2]){
		int c=a[2]-a[1];
		int q=c;
		while(m>=0){
			m-=q;
			if(m>=0){
				ans++;
			}
			q+=c;
			
		}
	}
	cout<<ans;
	return 0;
}
