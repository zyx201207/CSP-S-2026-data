#include<iostream>
#include<algorithm>
using namespace std;
long long va[500005];
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
//		for(int j=1;j<i;j++){
//			va[i]+=a[i]-a[j];
//		}
	}	
	sort(a+1,a+1+n);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		va[i]=va[i-1]+(a[i]-a[i-1])*(i-1);
		if(m>=va[i]){
			ans++;
		}
//		if(m<va[i]){
//			break;
//		}
	}
	if(m>=va[n]){
		cout<<ans;
	}
	else{
		cout<<ans;
	}
	return 0;
	
}
