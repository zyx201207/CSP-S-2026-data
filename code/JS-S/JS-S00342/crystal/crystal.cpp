#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n,ans;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=true;
	cin>>a[1]>>a[2];
	long long cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=cha){
			f1=false;
		}
	}
	sort(a+1,a+n+1);
	if(f1==true){
		if(cha<0){
			cha=0-cha;
		}
		for(int i=0;i<n;i++){
			if(m>=cha*i){
				m-=cha*i;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int k=n;k>=1;k--){
			for(int i=1;i+k-1<=n;i++){
				long long sum=0;
				for(int j=i;j<=i+k-1;j++){
					sum+=(a[i+k-1]-a[j]);
				}
				if(m>=sum){
					cout<<k;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
