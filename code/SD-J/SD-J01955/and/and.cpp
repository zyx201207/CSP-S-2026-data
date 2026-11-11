//I love CCF.
//Please give me more points.
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int er[55]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483647,4294967295};
int n,m,a[200005];
int mod=1073741823;
int ans=-1;
int vis[200005];
int fff[5];
bool cmp(int a,int b){
	return a>b;
}
int del(int a,int b){
	if(a>b){
		return a-b;
	}
	else{
		return b-a;
	}
}
void fun(int cnt,int p){
	if(p==m+1){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			fun(cnt&a[i],p+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){//6
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
		return 0;
	}
	else if(m==n){//7
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){//8~10
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=20){//1~5
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			fun(mod&a[i],1);
		}
		cout<<ans;
		return 0;
	}
	else{
		int f=1;
		for(int i=1;i<=n;i++){
			int mark=0;
			for(int j=0;j<=30;j++){
				if(a[i]==er[j]){
					mark=1;
				}
			}
			if(mark==0){
				f=0;
			}
		}
		if(f==1){//13
			sort(a+1,a+1+n,cmp);
			cout<<a[m];
			return 0;
		}
		else{
			int l=1;
			for(int i=1;i<=n;i++){
				if(a[i]>4){
					l=0;
				}
			}
			if(l==1){//16~17
				for(int i=1;i<=n;i++){
					fff[a[i]]++;
				}
				if(fff[2]>=1&&fff[3]>=1){
					fff[2]=0,fff[3]=0;
					m-=(fff[2]+fff[3]);
					if(m<=0){
						cout<<2;
						return 0;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					if(fff[3]>=1){
						if(fff[1]>=1){
							m-=fff[3];
							m-=fff[1];
							if(m<=0){
								cout<<1;
							}
							else{
								cout<<0;
							}
						}
						else{
							cout<<0;
						}
					}
					else{
						cout<<0;
					}
				}
				return 0;
			}
			else{
				sort(a+1,a+1+n,cmp);
				ans=a[1];
				for(int i=2;i<n;i++){
					ans&=a[i];
				}
				cout<<ans;
				return 0;
			}
		}
	} 
	return 0;
}
