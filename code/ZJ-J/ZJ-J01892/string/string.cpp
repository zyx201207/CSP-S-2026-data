#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	long long lz=a[1],rz=a[n];
	a[1]=0,a[n]=0;
	while(r!=l){
		if(lz>rz){
			lz-=rz;
			if(c[l] != c[r]){
				ans+=rz;
			}
			r--;
			if(a[r] == 0){
				cout<<ans;
				return 0;
			}
			rz=a[r];
			a[r]=0;
		}
		else if(lz<rz){
			rz-=lz;
			if(c[l] != c[r]){
				ans+=lz;
			}
			l++;
			if(a[r] == 0){
				cout<<ans;
				return 0;
			}
			lz=a[l];
			a[l]=0;
		}
		else{
			if(c[l] != c[r]){
				ans+=lz;
			}
			l++,r--;
			if(a[r] == 0 || a[l] == 0){
				cout<<ans;
				return 0;
			}
			lz=a[l],rz=a[r];
			a[l]=0,a[r]=0;
		}
	}
	cout<<ans;
	return 0;
}