#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
long long n,m,anspart,ans=0,m0,a[100001],s[100001];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){cin>>a[i]; s[i]=s[i-1]+a[i];} 
	
	sort(a,a+n);
	m0=m;
	
	
	for(int i=1;i<=n;i++){
		anspart=0;
		m=m0;
		for(int j=i;j>0;j--){
			m-=(a[i]-a[j]);
			if(m<0){
				break;
			}else{
				anspart++;
			}
			
		}
		ans=max(anspart,ans);
	}
	
	cout<<ans;
	
	return 0;
	
}
