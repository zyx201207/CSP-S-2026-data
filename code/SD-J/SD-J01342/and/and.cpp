#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],ksm[30],ks=1;
bool b1_1,b1_2,b2_1,b2_2,b3_1,b3_2,b4,bb,ba;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=30;i++){
		ksm[i]=ks;
		ks*=2;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)bb=1;
		if(a[i]==0)continue;
		if(a[i]>=4)b4=true;
		else if(a[i]==3){
			if(b3_1)b3_2=true;
			else b3_1=true;
		}else if(a[i]==2){
			if(b2_1)b2_2=true;
			else b2_1=true;
		}else if(a[1]==1){
			if(b1_1)b1_2=true;
			else b1_1=true;
		}
		for(int j=0;j<=30;j++)if(a[i]!=ksm[j])ba=1;
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++)x&=a[i];
		cout<<x;
		return 0;
	}
	if(!b4){
		if(b3_1&&b3_2){
			cout<<3;
			return 0;
		}
		if(b3_1){
			if(b2_1)cout<<2;
			else if(b1_1)cout<<1;
			else cout<<0;
			return 0;
		}
		if(b2_1&&b2_2){
			cout<<2;
			return 0;
		}
		if(b1_1&&b1_2){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(!ba){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if((!bb)&&m==2){
		cout<<n-2;
		return 0;
	}
	if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

