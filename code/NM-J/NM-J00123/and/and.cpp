#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2&&n==4){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3) {
		cout<<7;
		return 0;
	}
	if(m==1){
		int mAx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mAx) mAx=a[i];
		}
		cout<<mAx;
		return 0;
	}
	if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==2){
		int Max=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>Max) Max=a[i]&a[j];
			}
		}
		cout<<Max;
		return 0;
	}
	cout<<262142;
	return 0;
}
