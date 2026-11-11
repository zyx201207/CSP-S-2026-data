#include<bits/stdc++.h>
using namespace std;
int n,vl[200005],vr[200005];
unsigned long long a[200005],ans;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
	}
	int l=1,r=n,k=0;
	while(l<r){
		if(c[l]!=c[r]){
			int xx=max(a[l-1],a[n]-a[r]);
			int yy=min(min(a[n]-a[l],a[l]),min(a[n]-a[r-1],a[r-1]));
			k++;
			vl[k]=xx;
			vr[k]=yy;
		}
		if(a[l]>=a[n]-a[r-1]){
			r--;
		}else{
			l++;
		} 
	}
	for(int i=1;i<=k;i++){
		ans+=vr[i]-vl[i];
	}
	cout<<ans;
	return 0;
} 
