#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],num[500005],js;
int sum=1;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		num[i]=a[i]-a[i-1];
	}
	int d=m;
	for(int i=1;i<=n;i++){
		sum=1;
		js=0;
		d=m;
		for(int j=i;j>=0;j--){
			js+=num[j];
			if(d-js>=0){
				d-=js;
				sum++;
			}else{
				ans=max(ans,sum);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
	}
