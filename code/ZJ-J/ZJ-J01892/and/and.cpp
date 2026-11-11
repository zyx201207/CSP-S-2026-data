#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	int mx=0;
	int a1=0,a2=0,a3=0,a0=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(a[i] == 1) a1++;
		else if(a[i] == 2) a2++;
		else if(a[i] == 3) a3++;
		else if(a[i] != 0) a0=0;
	}
	
	
	if(m == 1) cout<<mx;
	else if(m == 2){
		int ans1=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1;
	}
	else if(m == n){
		int ans2=a[1];
		for(int i=2;i<=n;i++){
			ans2=ans2&a[i];
		}
		cout<<ans2;
	}
	else if(m == n-1){
		int ans3=0;
		for(int i=1;i<=n;i++){
			int x;
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				if(j == 1 || (j == 2 && i == 1)){
					x=a[j];
				}
				else x&=a[j];
			}
			ans3=max(ans3,x);
		}
		cout<<ans3;
	}
	else if(a0){
		if(a3 >= m) cout<<3;
		else if(a2+a3 >= m) cout<<2;
		else if(a1+a3 >= m) cout<<1;
		else cout<<0;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}