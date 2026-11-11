#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[200005],cnt=0,sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(size_t i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i]; 
	}
	ll half=sum/2;
	ll j=n-1,i=0,tmp=0;
	while(half>0){
		tmp=min(a[j],a[i]);
		half-=tmp;a[i]-=tmp;a[j]-=tmp;
		if(c[i]!=c[j]) 
			cnt+=tmp;
		if(a[i]==0)
			i++;
		if(a[j]==0) 
			j--;
	}
	cout<<cnt;
	return 0;
}
