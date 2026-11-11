#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,n,m;//mj mianji,he qian zhui he
bool tepa=1,tepb=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long nn=n;
	long long ls=0;
	for(long long i=1;i<=n; i++){
		cin>>a[i];
		if(a[i]!=i)tepa=0;
		if(i>3&&a[i]-a[i-1]!=ls){
			tepb=0;
		}
	//	cout<<ls<<' '<<a[i]<<' '<<a[i-1]<<endl;
		if(i>1)ls=a[2]-a[1];
	//cout<<i<<' ';
	}
	if(m==0||n==1){
		cout<<1;
		return 0;
	}
	if(tepa){
			ans=0;
		while(1==1){
			ans+=1;
			if(m<((ans*(ans+1))/2)){
				ans-=1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}	
	if(tepb){
			ans=0;
			m/=(a[3]-a[2]);
		while(1==1){
			ans+=1;
			if(m<((ans*(ans+1))/2)){
				ans-=1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	n=nn;
	ans=0;
	for(long long i=1;i<=n;i++){
		long long ls=0,ls2=0; 
		for(int k=i-1;k>=0;k--){
			ls+=a[i]-a[k];
			if(ls>m){
				break;
			}
			ls2=i-k;
		}
		ans=ans>ls2?ans:ls2;
	}
	cout<<ans+1;
	return 0;
}
