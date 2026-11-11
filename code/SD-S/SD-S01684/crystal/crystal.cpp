#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n,m;
int a[N];
int b[N];
int sum;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=1;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	//	cout<<a[i]<<" ";
	}
	if(f==0){
		for(int i=n;i>=1;i--){
			m-=b[i];
			sum++;
			if(m<0){
				cout<<sum-1;
				return 0;
			}
		}
	}
	else if(n<=5000){
		for(int i=n;i>=1;i--){
			int h=m;
			int o=0;
			for(int j=i;j>=1;j--){
				h=h-(b[j]-b[i]);
				o++;
				if(h<0){
					sum=max(sum,o-1);
					break;
				}
			}
		}
	}
	else{
		int o;
		for(int i=n;i>=1;i--){
			int h=m;
			for(int j=i;j>=1;j--){
				if(i!=n){
					o--;
					j-=o;
				}
				h=h-(b[j]-b[i]);
				o++;
				if(h<0){
					sum=max(sum,o-1);
					break;
				}
				
			}
		}
	}
	cout<<sum;
	return 0;
}
