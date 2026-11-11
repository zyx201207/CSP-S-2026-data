#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500001],q,c=1,ans=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	for(long long i=2;i<n;i++){
		for(long long j=i-1;j>=0;j--){
			if(m>=a[i]-a[j]){
				c++;
				m-=a[i]-a[j];
			}else{
				if(ans<c){
					ans=c;
					c=1;
				}
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
