#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,flag;
int h[500005];
void solve1(){
	for(int i=2;i<=n;i++){
		if(a[i]==a[i+1])continue;
		int k=m,res=0;
		for(int j=i;j>=1;j--){
			k-=a[i]-a[j];
			if(k<0)break;
			res++;
		}
		ans=max(ans,res);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	flag=1;
	int cha;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)continue;
		else if(i==2)cha=a[i]-a[i-1];
		else {
			if(a[i]-a[i-1]!=cha)flag=0;	
		}
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		solve1();
		return 0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			h[i]=h[i-1]+a[i];
			if(m==h[i]){
				cout<<i+1;
				break;
			}
			else if(m<h[i]){
				cout<<i;
				break;
			}
		}	
	}
	else{
		for(int i=1;i<=n;i++){
			h[i]=h[i-1]+i*(a[i+1]-a[i]);
			if(m==h[i]){
				cout<<i+1;
				break;
			}
			else if(m<h[i]){
				cout<<i;
				break;
			}
		}	
	}
	return 0;
} 
