#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5e5+1;

ll n,m,ans=0,l,sum=0,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,l=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);//加上r的贡献 
		while(sum>m&&l<=i)
			sum-=a[i]-a[l],l++;//减去l的贡献 
		if(i-l+1>ans)
			ans=i-l+1;
	}
	cout<<ans;
}
