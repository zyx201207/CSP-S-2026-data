#include<bits/stdc++.h>
using namespace std;
int n,ans=1,ans2=0,a[110000];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int s=n/2;
	for(int i=s-1;i>0;i--){
		if(m<a[s]-a[i]){
			break;
		}
		else{
			m-=a[s]-a[i];
			ans++;
		}
	}
	if(m>0){
		for(int i=s+1;i<=n;i++){
			if(m<ans*(a[i]-a[s])){
				break;
			}
			m-=ans*(a[i]-a[s]);
		    ans2++;
			}
	}	
	cout<<ans+ans2;
	return 0;
}
