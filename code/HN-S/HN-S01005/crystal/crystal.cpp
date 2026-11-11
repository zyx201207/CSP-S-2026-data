#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,m,a[N],ans=1; 
void slove1(){
	for(int i=2;i<=n;i++){
		int num=m,f=0;
		for(int j=i-1;j>=1;j--){
			if(num>=a[i]-a[j])num=num-(a[i]-a[j]);
			else{
				ans=max(ans,i-j);	
				f=1;
				break;
			} 
		}
		if(f==0)ans=max(ans,i);
	}
	cout<<ans;
}
void slove2(){
	for(int i=2;i<=n;i++){
		int zhi=(a[i]-a[i-1])*(i-1);
		if(m>=zhi){
			m-=zhi;
		}else{
			cout<<i-1;
			break;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		slove1();
	}else{
		slove2();
	}
	
	
	
	return 0;
} 

