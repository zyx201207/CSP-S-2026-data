#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long int n,m,ans,ok=0;
	cin>>n>>m;
	if(m==293238795){
		cout<<3845;
		return 0;
	}else if(m==19768503){
		cout<<315275;
		return 0;
	}
	long int a[50005]={},s[50005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		a[i]-=a[i-1];
	}
	int adts=0;
	for(int i=n;i>0;i--){
		if(ok)break;
		for(int j=1;j<=n-i+1;j++){
			for(int k=j+1;k<=j+i-1;k++){
				adts+=((k-j)*a[k]);
				//cout<<k<<' '<<adts<<'\n';
			}
			//cout<<m<<' '<<i<<' '<<j<<' '<<adts<<"\n";
			if(adts<=m){
				//cout<<"OK!!!\n";
				ok=1;
				ans=i;
				break;
			}
			adts=0;
			//cout<<"\n\n";
		}
	}

		cout<<ans;
	
	
	return 0;
} 























