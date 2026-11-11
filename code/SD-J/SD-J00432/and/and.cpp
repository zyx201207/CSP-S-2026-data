#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num[25];
long long ans=-1,tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>tmp;
			max(ans,tmp);
		}
		cout<<ans;
	}
	else if(m==n){
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>tmp;
			ans&=tmp;
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				ans=max(ans,num[l]&num[r]);
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		sort(num+1,num+n+1);
		cout<<num[n-m+1];
	}
	return 0;
}
