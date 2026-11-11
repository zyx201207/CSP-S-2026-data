#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long n,m,k,ckk,s,ans=0,mmm;
long long a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;

	;
	for(int i=1;i<=n;i++){
		cin>>k;
		a[i]=k-a[i-1];
	}

	sort(a+1,a+1+n);
	ckk=m;
	for(int i=1;i<=n;i++){

		if(a[i]*i<=ckk){

			ckk-=a[i]*i;
			s+=a[i];

		}
		else if((s+m)/(i-1)>=a[i]){



			s+=(s+m)%(i-1);
		}
		ans=max(ans,s);
			cout<<ans;

	}
	cout<<ans;






	return 0;
}
