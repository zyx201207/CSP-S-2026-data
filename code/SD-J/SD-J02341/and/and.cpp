#include<bits/stdc++.h>
using namespace std;
int n,m,x;
long long l[100005],mmax=0,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			mmax=max(mmax,l[i]);
		}
		cout<<mmax;
	}
	else if(m==n){
		ans=l[0];
		for(int i=1;i<n;i++){
			ans=ans&l[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j!=i) mmax=max(l[i]&l[j],mmax);
			}
		}
		cout<<mmax;
	}
	else{
		ans=l[0];
		for(int i=1;i<n;i++){
			ans=ans&l[i];
		}
		cout<<ans;
	} 
	return 0;
}
