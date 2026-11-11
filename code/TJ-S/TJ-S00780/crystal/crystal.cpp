#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5*1e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k=1;
	ll m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int b=a[1];
	bool f=true;
	for(int i=1;i<=n;i++){
		if(b!=a[i])f=false;
	}
	if(f){
		cout << n;
	}else {
		for(int i=n;i>=1;i--){
			int ans=1;
			int h=m;
			for(int j=i-1;j>=1;j--){
				h-=a[i]-a[j];
				a[j]=a[i];
				if(h<=0){
					break;
				}
				ans++;
			}
		k=max(ans,k);
		}
		cout << k;
		
	}
	return 0;
} 
