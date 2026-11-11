#include <bits/stdc++.h>
using namespace std;

unsigned long long m;
long long a[500005];
int n;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool flag=true; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		a[i]=a[i+1]-a[i];
		if(i>=2&&a[i]!=a[i-1]){
			flag=false;
		}
	}
	a[n]=0;
	long long d=a[1];
	if(flag==true){
		for(int i=0;i<=n;i++){
			long long get=d*i*(i+1)/2;
			if (get>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	//±©Á¦
	int ans=0;
	for(int i=1;i<=n-1;i++){
		int right=i;
		long long rem=0,need=0;
		for(int j=i;j>=1;j--){
			need=need+rem+a[j];
			rem+=a[j];
			if(need>m||j==1){
				if(j==1&&need<=m){
					if(right-j+2>ans){
						ans=right-j+2;
					}
					break;
				}
				else if(right-j+1>ans){
					ans=right-j+1;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
