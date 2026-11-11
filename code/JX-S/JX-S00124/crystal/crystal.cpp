#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long mx,l,len;
long long a[5000005];
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	l=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		len++;
		sum+=a[i];
		while(sum+m<len*a[i]){
			sum-=a[l++];
			len--;
		}
		mx=max(mx,len);
	}
	cout<<mx;
	return 0;
}
