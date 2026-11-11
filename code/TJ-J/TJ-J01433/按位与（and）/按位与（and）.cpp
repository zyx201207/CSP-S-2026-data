#include<bits/stdc++.h>
using namespace std;
long long a[200000000000005],b[200000000000005];
int main(){
	freopen("按位与（and）.in","r",stdin);
	freopen("按位与（and）.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		} 
		cout<<ans;
	}
	else if(m==2){
		long long tot=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[tot]=a[i]&a[j];
				tot++;
			}
		}
		sort(b+1,b+1+tot);
		cout<<b[tot];
	}
	else{
		cout<<"0";
	}
	return 0;
}
