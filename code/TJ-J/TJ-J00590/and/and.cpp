#include<iostream>
using namespace std;
int n,m,arr[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,arr[i]);
		}
	}else if(m==n){
		ans=arr[1];
		for(int i=2;i<=n;i++){
			ans&=arr[i];
		}
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,arr[i]&arr[j]);
		}
	}else{
		cout<<"CCF I Love U!";
	}
	cout<<ans;
	return 0;
}
