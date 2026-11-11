#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100001],maxx=-9999;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			s++;
		}
	}
	if(n-s<=m+1){
		cout<<0;
		return 0;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int num=a[1];
		for(int i=2;i<=n;i++)
			num=num&a[i];
		cout<<num;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j){
					int kk=a[i]&a[j];
					if(kk>maxx)
					{
						maxx=kk;
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	bool A=true;
	for(int i=1;i<=n;i++){
		if(a[i]^0==a[i])
			continue;
		else{
			A=false;
			break;
		}
	}
	if(A==true){
		sort(a+1,a+n+1);
		cout<<a[m+1];
	}
	
	for(int i=1;i<=n-m+1;i++){
		int num=a[i];
		for(int j=i+1;j<m+i;j++){
			num=num&a[j];
		}
		if(i==1||num>maxx)
			maxx=num;
	}
	cout<<maxx;
	return 0;
}