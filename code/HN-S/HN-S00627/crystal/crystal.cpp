#include<bits/stdc++.h>
using namespace std;
int a[500001],ans[500001],m,n;
void sort(int r,int l){
		for(int i=r;i<=l-1;i++){
			for(int j=i+1;j<=l;j++){
				if(a[j]<a[i]){
					int u=a[j];
					a[j]=a[i];
					a[i]=a[u];
				}
			}
		}
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int b=0,v=0,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];ans[i]=0;
		if(i>=2&&a[i]==a[i-1])v++;
		if(i>=3&&a[i]-a[i-1]==a[i-1]-a[i-2]){
			z++;
		}
	}
	if(v==n-1)cout<<n;
	else{
		if(z==n-2){
			int g=a[2]-a[1];
			if(a[2]<a[1]){
				g=-g;
			}
			m=m/g;int f=0;
			for(int i=1;i<=m;i++){
				f=f+i;
				if(f>m){
					cout<<i;
					break;
				}
				
			}
		}
		else{
		sort(1,n);
		for(int i=2;i<=n;i++){
		int t=0;
		for(int j=n-1;j>=1;j--){
			if(m<t)break;
			t=t-a[j]+a[i];
			ans[i]++;
		}
		for(int j=i;j<=n;j++){
				if(a[j]==a[i]){
					ans[i]++;
				}
				else{
					break;
				}
			}
			if(ans[i]>b){
				b=ans[i];
			}
		}
		cout<<b-2;
		}
	}
	return 0;
}
