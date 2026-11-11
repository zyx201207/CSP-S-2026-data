#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],l,r,qian[200001],ans,maxx,cha;
char b[200001];
string m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]+a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	l=1;
	r=n-1;
	maxx=qian[n];	
	while(l<=r){
		if(b[l]==b[r+1]){
			if(qian[l]+qian[r]>maxx){
				r--;
			}else if(qian[l]+qian[r]<maxx){
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(qian[l-1]+1<=maxx-qian[r+1]+1){
				if(qian[l]>=maxx-qian[r]){
					ans=ans+qian[r+1]-qian[r];
				}else if(qian[l]<=maxx-qian[r]){
					ans=ans+qian[l]-maxx+qian[r+1];
				}
			}else if(qian[l-1]+1>maxx-qian[r+1]+1){
				if(qian[l]>=maxx-qian[r]){
					ans=ans+maxx-qian[r]-qian[l-1];
				}else if(qian[l]<=maxx-qian[r]){
					ans=ans+qian[l]-qian[l-1];
				}
			}
			
			if(qian[l]+qian[r]>maxx){
				r--;
			}else if(qian[l]+qian[r]<maxx){
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

 
 






