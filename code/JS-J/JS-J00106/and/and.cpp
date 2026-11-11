#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma,x,c1,c2,c3,maa,ans;
bool check(long long n){
	for(long long i=1;i<=n;i++){
		int f=1;
		for(int j=0;j<=20;j++){
			if(a[i]==pow(2,j)-1){
				f=0;
				break;
			}
		}
		if(f){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1){
			x=a[i];
		}else{
			x=x&a[i];
		}
	}
	if(m==1){
		cout<<ma;
	}else if(m==n){
		cout<<x;
	}else if(ma<4){
		for(long long i=1;i<=n;i++){
			if(a[i]==1){
				c1++;
			}if(a[i]==2){
				c2++;
			}if(a[i]==3){
				c3++;
			}
		}
		if(c3>=m){
			cout<<3;
		}else if(c2+c3>=m){
			cout<<2;
		}else{
			cout<<0;
		}
	}else if(m==2){
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				maa=max(maa,a[i]&a[j]);
			}
		}
		cout<<maa;
	}else if(check(n)){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}else if(m==n-1){
		sort(a+1,a+n+1,greater<int>());
		for(long long i=1;i<=m;i++){
			if(i==1){
				ans=a[i];
			}else{
				ans=ans&a[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
