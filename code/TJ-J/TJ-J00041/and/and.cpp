#include <bits/stdc++.h>
using namespace std;
long long a[100005],ab[5];
long long m,n,ans,sp;
bool flag=1,fl2=1;
bool cmp(int a,int b){
	return a>b; //大到小 
}
bool two(int s){ //2的k次方判断 
	while(s>2){
		s/=2;
		if(s==2) return true;
	}
	return false;
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sp=a[i];
		else sp=sp&a[i];
		if(a[i]!=i-1) flag=0;
		if(a[i]>=4) fl2=0;
		if(a[i]<4) ab[a[i]]++;
	}
	sort(a+1,a+1+n,cmp);
	if(fl2==1){
		if(ab[1]==m){
			cout<<1; return 0;
		}if(ab[2]==m){
			cout<<2; return 0;
		}if(ab[3]==m){
			cout<<3; return 0;
		}else{
			cout<<a[1]-1; return 0;
		}
	}
	if(m==1){
		cout<<a[1]; return 0;
	}
	if(m==n){
		cout<<sp; return 0;
	}
	if(flag=1){
		ans=a[m]&a[1];
		cout<<ans;
		return 0;
	}
	int k=n&n-1;
	if(k==0){
		if(m==2){
			cout<<a[1]-1; return 0;
		}
		cout<<a[1]-3; return 0;
		return 0;
	}
	if(m==2){
		int mi=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans=a[i]&a[i+1];
				cout<<ans; return 0;
			}
			if(!two(a[i])&&mi==1){
				ans=a[i]&a[i-1];
				cout<<ans; return 0;
			}
			if(two(a[i])) mi=0;
			else mi++;
		}
		if(two(a[1])) ans=a[2]&&a[3];
		else ans=a[1]&a[2];
		cout<<ans; return 0;
	}
	return 0;
}

