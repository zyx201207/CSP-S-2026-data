#include<bits/stdc++.h>
using namespace std;
long long a[5*100000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	bool flag=0;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i&&a[i]-a[i-1]!=a[i-1]-a[i-2])
			flag=1;
	}
	if(flag==1){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				flag=0;
			else
				flag=1;
		}
	}
	if(flag==0){
		//~ cout<<"flag=0\n";
		for(int i=2;i<=n;i++){
			long long ans;
			ans=(a[1]+a[i])*((a[i]-a[1])/(a[2]-a[1])+1)/2;
			if(m<ans){
				cout<<i;
				return 0;
			}if(i==n){
				cout<<n-(m-ans)%n;
				return 0;
			}
		}
	}
	if(n<17&&m<1001){
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int jb=1,c=0;
			for(int j=i+1;j<=n;j++){
				c+=(a[i]-a[j]);
				if(m<c){
					ans=max(ans,jb);
					break;
				}
				jb++;
				//~ cout<<a[j]<<" ";
			}
			ans=max(ans,jb);
			//~ cout<<jb<<"\n";
		}
		cout<<ans;
	}
}
