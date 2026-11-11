#include <bits/stdc++.h>
using namespace std;
int n,len=0;
long long a[200005],l[200005],r[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l2=1,r2=n;
	long long ans=0;
	while(l2<=r2){
		if(c[l2]!=c[r2])
			ans+=min(a[l2],a[r2]);
		if(a[l2]<a[r2]){
			a[r2]-=a[l2];
			l2++;
		}
		else if(a[l2]>a[r2]){
			a[l2]-=a[r2];
			r2--;
		}
		else{
			l2++;
			r2--;
		}	
	}
	cout<<ans;
	return 0;
}

