#include<bits/stdc++.h>
using namespace std;
long long a[600000];
long long n,m,ans=0,kk;
bool c_d=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=LONG_LONG_MIN,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	kk=a[2]-a[1];
	for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=kk) c_d=0;
	if(c_d){
		cout<<min((long long)sqrtl((long long)m*2/kk)+1,n); //(i-1)*i*kk<=m*2
		return 0;
	}for(int i=1;i<=n;i++){
		long long k=1,sum=0;
		for(int j=1;j<=n;j++){//----------
			if(a[i]>a[j]){//             |
				sum+=a[i]-a[j],k++;//    |
				if(sum>m) break;//       |
			}//how to make it O(1)?<-----
		}ans=max(ans,k);
	}cout<<ans;///75 points
	return 0;
}//maybe yellow