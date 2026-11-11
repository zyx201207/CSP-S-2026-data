#include<bits/stdc++.h>
using namespace std;
long long a[200010],L,n;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])L+=min(a[l],a[r]);
		if(a[l]<a[r])a[r]-=a[l],l++;
		else if(a[l]>a[r])a[l]-=a[r],r--;
		else if(a[l]==a[r])l++,r--;
	}
	cout<<L;
	return 0;
}
