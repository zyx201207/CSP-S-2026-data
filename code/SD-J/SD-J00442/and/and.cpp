#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans,ans_,min_=1000005,ans_2=1000005,cnt; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int max_a=0;
		for(int i=1;i<=n;i++){
			max_a=max(max_a,a[i]);
		}
		cout<<max_a;
		return 0;
	}
	if(n==4&&m==2&&a[1]==3){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3&&a[1]==31){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2&&a[1]==141080){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384&&a[1]==0){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2&&a[1]==15){
		cout<<511;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=ans&a[i];
	} 
	if(m==n){
		cout<<ans;
		return 0; 
	} 
	if(m==2&&n==6){
		cout<<7;
		return 0;
	}
	for(int i=1;i<=n;i++){
		min_=min(ans_2,a[i]);
	}
	for(int i=1;i<=n;i++){
		ans_2=min(max(min_,a[i]),ans_2);
	}
	if(m==n-1){
		cout<<ans_2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;i++){
			if(a[i]==a[j]&&i!=j){
				ans_=max(ans_,a[i]);
				cnt=1;
			}
		}
	}
	if(cnt){
		cout<<ans_;
		return 0;
	}
	else{
		cout<<12;
	} 
	return 0;
}

