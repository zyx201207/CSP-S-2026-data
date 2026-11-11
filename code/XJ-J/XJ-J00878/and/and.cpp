#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200000];
bool check(int w){
	while(w>0){
		if(w%2!=0){
			return false;
		}
		w=w/2;
	}
	return true;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		ans=-1e9;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==2){
		sort(a+1,a+1+n);
		int ji,ou;
		if(a[n]%2==0){
			for(int i=n-1;i>=1;i--){
				if(a[i]%2==0 && (ji==1 && ou==0)){
					ans=a[i];
			}
				if(a[i]%2==1){
					ji++;
				}else{
					ou++;
				}
				
			}
		}else{
			for(int i=n;i>=1;i--){
				if(check(a[i])){
					ans=a[i];
				}
			}
		}
	}
	cout<<ans;
	return 0;
	
}
