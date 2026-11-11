#include<bits/stdc++.h>
using namespace std;
int dp[200005],a[200005];
int n,m,s=1073741823,q;
int b[25]={256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152};
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	/*for(int i=n;i>0;i--){
		//cout<<s<<"*";
		cout<<a[i]<<" ";
	}	
	cout<<'\n'<<'\n';*/
	for(int i=n;i>n-m;i--){
		int f=0;
		for(int j=0;j<15;j++){
			if(a[i]==b[j]){
				f=1;
				q++;
			}
		}
		if(f==0){
			s=s&a[i];
			//cout<<a[i]<<" "<<s<<'\n';
		}
		
	}
	for(int i=n-m;i>n-m-q;i--){
		s=s&a[i];
		//cout<<a[i]<<" "<<s<<'\n';
	}
	cout<<s;

	return 0;
}
