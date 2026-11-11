#include<bits/stdc++.h>
using namespace std;
long long int maxn,s,mid,n,m,a[500005],t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],t[i]=a[i];
	sort(a+1,a+1+n);
	mid=(n+1)/2;
	for(int i=mid;i<=n;i++){
		int t1=m;
		for(int j=1;j<i;j++){
			if(t1-(a[i]-a[j])>=0){
				t1-=(a[i]-a[j]);
				t[j]=a[i];
			}
		}
		s=0;
		for(int j=1;j<=i;j++){
			if(t[j]==t[i]) s++; 
			t[j]=a[j];
		}
		maxn=max(maxn,s);
	}
	cout<<maxn<<endl;
	return 0;
}

