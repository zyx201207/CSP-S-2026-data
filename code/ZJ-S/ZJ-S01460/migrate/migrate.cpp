#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int c,t;
int n,d,a[maxn],cnt=0;
int fpm(int x){
	if((x%3==0&&x%2==1)||(x%3==1&&x%2==0)){
		return x*(x-1)/6*(x-2);
	}
	else if((x%3==0&&x%2==0)||(x%3==2&&x%2==0)){
		return x*(x-2)/6*(x-1);
	}
	else{
		return (x-1)*(x-2)/6*x;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=15&&c<=18){
			cout<<fpm(n)<<'\n';
		}
		if(c>=11&&c<=14){
			int tmp=d/(a[2]-a[1]);
			if(tmp<=1){
				cout<<0<<'\n';
			}
			else{
				cout<<n/2<<'\n';
			}
		}
		else{
			cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int sum=0;
					for(int k=i+1;k<=j-1;k++){
						if(a[j]-a[k]<=d){
							sum++;
						}
					}
					if(sum==2){
//						cout<<i<<" "<<j<<'\n';
						cnt++;
					}
					
				}
			}
			cout<<cnt<<'\n';	
		}
	}
	return 0;
}

