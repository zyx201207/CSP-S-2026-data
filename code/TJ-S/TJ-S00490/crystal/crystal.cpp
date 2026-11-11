#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long ans=1;
int t=1;
map <long long,long long> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
		if(a[i]!=i){
			t=0;
		}
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(t){
		long long i=1;
		while(1){
			if(m-i>=0){
				m-=i;
				i++;
			}
			else
				break;
		}
		cout<<i;
		return 0;
	}
	if(m==0) 
		cout<<ans;
	else{
		ans=1;
		sort(a+1,a+n+1);
		for(long long i=2;i<=n;i++){
			for(long long j=1;j<i;j++){
				if((i-j)*a[i]<=m+b[i-1]-b[j-1])
					ans=max(ans,i-j+1);
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
