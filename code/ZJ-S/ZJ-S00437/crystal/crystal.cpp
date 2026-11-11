#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010];
map<long long,int>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=a[1];i<=a[n];i++){
		int pos=upper_bound(a+1,a+n+1,i)-a;
		pos-=mp[i];
		pos--;
		long long sum=0,t=0;
		int k;
		for(int j=pos;j>=1;j--){
			sum+=i-a[j];
			if(sum>m)break;
			k=pos-j+1;
			t=sum;
		}
		long long r=0;
		if(k+mp[i]<=m-t){
			r=i+(m-t)/(k+mp[i]);
		}
		k=k+mp[i]+mp[r];
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}