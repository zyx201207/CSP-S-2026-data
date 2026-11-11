#include<bits/stdc++.h>
using namespace std;
long long n,m,a[6000000],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long k=0,ff=1,b,biao=n-1;
	bool flag=0;
	for(int i=n;i>=1;i--){
		if(i!=n){
			k=k-(a[i+1]-a[i])*(ff-1);
			ff--;
		}
		if(flag==1) break;
		flag=1;
		for(int j=biao;j>=1;j--){
			b=a[i]-a[j];
			if(k+b<=m){
				k+=b;
				ff++;
			}
			else{
				flag=0;
				biao=j;
				break;
			}
		}
		ans=max(ans,ff);
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
