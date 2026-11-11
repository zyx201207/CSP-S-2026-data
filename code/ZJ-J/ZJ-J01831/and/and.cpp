#include<bits/stdc++.h>
using namespace std;
int n,m,index;
long long k,a[200010],pos[200010][30],num[31],ans,maxn;
int can_try;
long long pw(int x){
	long long y=1;
	for(int i=1;i<=x;i++){
		y*=2;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==1){
			maxn=max(maxn,a[i]);
		}
		k=a[i];
		for(int j=0;j<=30;j++){
			pos[i][j]=k%2;
			k/=2;
			if(j==0){
				if(pos[i][j]==0){
					flag=0;
				}
			}else{
				if(pos[i][j]==0&&pos[i][j-1]==1){
					flag=0;
				}
			}
			num[j]+=pos[i][j];
		}
	}
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}
	if(flag==1){
		sort(a,a+n);
		cout<<a[n-m]<<endl;
		return 0;
	}
	for(int i=30;i>=0;i--){
		if(num[i]>=m){
			can_try=i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(!pos[i][can_try]){
			for(int j=0;j<=30;j++){
				num[j]-=pos[i][j];
			}
		}else{
			maxn=max(maxn,a[i]);
		}
	}
	cout<<maxn<<endl;
	return 0;
}
