#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,a[500100]={},l=1,r=1,res=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		while(r<=n){
			int cnt=0;
			while(a[l]+d>=a[r])r++;
			for(int i=l+1;i<r;i++){
				if(a[i]>=a[r]-d&&a[i]<=a[l]+d){
					cnt++;
				}
				if(cnt>2){
					r++;
					break;
				}
			}
			if(cnt==2){
				res++;
				l++;
			}else if(cnt<2){
				l++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
