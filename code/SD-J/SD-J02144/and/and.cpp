#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int ans1=0;
		for(int i=1;i<=n;i++)
			ans1=max(ans1,a[i]);
		cout<<ans1;
		return 0;
	}
	if(m==n){
		int ans2=a[1];
		for(int i=2;i<=n;i++)
			ans2=ans2&a[i];
		cout<<ans2;
		return 0;
	}
	if(m==2){
		int ans3=0;
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
				ans3=max(ans3,a[i]&a[j]);
		cout<<ans3;
		return 0;
	}
	if(m==n-1){
		int ans4=0;
		for(int i=1;i<=n;i++){
			int cnt=1;
			for(int j=1;j<=n;j++)
				if(j!=i)
					cnt=cnt&a[j];
			ans4=max(ans4,cnt);
		}
		cout<<ans4;
		return 0;	
	}
	return 0;
}
