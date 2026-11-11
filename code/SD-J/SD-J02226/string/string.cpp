#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
int ax[100005];
string cx;
long long ans=0,num=0,wo=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ax[i]>>cx[i];
		wo+=ax[i];
		if(i<=n/2)
		num+=ax[i]; 
	}
	
	if(n%2==0){
		for(int i=0;i<n/2;i++){
		if(cx[i]!=cx[n-1-i]){
			if(ax[i]<=ax[n-1-i]){
				ans+=ax[i];
			}else ans+=ax[n-1-i];
		}
	}
	}else{
		if(wo/2<num)
		ans+=ax[n/2];
		else{
			if(wo/2==num)
			ans+=ax[n/2]-1;
			else{
				ans+=ax[n/2]-wo/2+num;
			}
		}
	}
	
	cout<<ans;
	return 0;
} 
