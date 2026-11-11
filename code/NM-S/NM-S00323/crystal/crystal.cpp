#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==2){
		if(a[1]+m>=a[2]){
			cout<<2;
		}
	}
	int num=a[2]-a[1],ans=0,sum1=1;
	while(m>0){
		if(m-num*sum1<0){
			break;
		}
		m-=num*sum1;
		ans++;
		sum1++;
	}
	cout<<ans+1;
	return 0;
} 
