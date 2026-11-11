#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cj[500005],num,sum,ans,flag=1,flag2=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			num=1;
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]+sum<=m){
					sum=a[i]-a[j]+sum;
					num++;
				}
				else{
					break;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;
		return 0;
	}
	if(flag==1){
		int i=0,ls=0;
		while(1){
			if(ls>m){
				i--;
				break;
			}
			if(i+1==n){
				break;
			}
			i++;
			ls=ls+i;
		}
		cout<<i+1;
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag2=0;
		}
	}
	if(flag2==1){
		int i=0,ls=0,js=0;
		while(1){
			if(ls>m){
				js--;
				break;
			}
			if(js+1==n){
				break;
			}
			i+=a[2]-a[1];
			ls=ls+i;
			js++;
		}
		cout<<js+1;
		return 0;
	}
}
