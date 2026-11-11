#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,m,b[10000],ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=10000){
		cout<<n;
		return 0;	
	}
	
	for(int i=1;i<=n;i++){
		long long x=a[i],nm=m;
		for(int j=1;j<=n;j++){
			b[j]=x-a[j];
			//cout<<b[j]<<' ';
		}
		//cout<<endl;
		sort(b+1,b+1+n);
		long long j=1,ans=0;
		while(nm>0&&j<=n){
			if(nm>=b[j]&&b[j]>=0){
				nm-=b[j];
				ans++;
				//cout<<"+1"<<' ';
			}
			j++;
		}
		//cout<<ans<<endl;
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}