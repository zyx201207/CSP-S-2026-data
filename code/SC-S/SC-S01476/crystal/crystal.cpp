#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans=-1e9,c,ma;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c=m;
		ma=0;
		int k=1;
		//cout<<a[i]<<" ";
		while(c>0&&i-k>0){
			c-=a[i]-a[i-k];
			//cout<<a[i-k]<<":"<<a[i]-a[i-k]<<" ";
			if(c>=0){
				ma++;
				k++;
			}
		}
		//cout<<"\n";
		ans=max(ans,ma);
	}
	cout<<ans+1;
	return 0;
} 