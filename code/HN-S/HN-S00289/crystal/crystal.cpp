#include<bits/stdc++.h>
using namespace std;

long long n=0,a[500086],m,loss[500086];
long long cmpsum=-1e12-999,ans=0;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	loss[0]=a[0];
	for(int i=1;i<n;i++){
		loss[i]=a[i]+loss[i-1];
	}
	
		for(int left=0;left<n;left++){
			long long flag=0;
			for(int right=left+1;right<n-1&&flag==0;right++){
				int timesum=0;
				timesum=(a[right+1]*(right-left+1))-loss[right]+loss[left-1];
				
				if(timesum<=m&&timesum>=cmpsum&&right-left>=ans){
					ans=right-left;
					cmpsum=timesum;
				}
				else{flag=1;}
			}
		}
		cout<<ans+2;
	return 0;
}
