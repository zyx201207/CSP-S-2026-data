#include<bits/stdc++.h>
using namespace std;
#define int long long
int cmp=0,cmp2=0,n,m,a[1000000],s1=0,s2=0,s3=0,s4=0;
bool check(int x){
	int abc=1,ab=0;
	while(ab<25){
		if((abc-1)==x){
			return true;
		}
		abc*=2;
		ab++;
	}
	return false;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s1++;
		}
		if(a[i]==2){
			s2++;
		}
		if(a[i]==3){
			s3++;
		}
		if(a[i]==4){
			s4++;
		}
		if(check(a[i])==false){
			cmp=1;
		}
	}
	sort(a+1,a+1+n);
	if(!cmp){
		cout<<a[n-m+1];
		return 0;
	}
	else{
		if(s4>=m){
			cout<<4;
			return 0;
		}
		if(s3>=m){
			cout<<3;
			return 0;
		}
		if(s2+s3>=m){
			cout<<2;
			return 0;
		}
		if(s3+s1>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
