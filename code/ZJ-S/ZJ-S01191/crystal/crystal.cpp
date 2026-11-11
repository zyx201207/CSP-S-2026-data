#include<bits/stdc++.h>
using namespace std;
int n,maxn;
long long m,a[500005],suf[500005];
bool flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		suf[i]=a[i+1]-a[i];
		if(i!=1 && suf[i]!=suf[i-1]) flag2=0; 
	}
    if(flag2){
    	if(floor((suf[1]+sqrt(suf[1]*suf[1]+8*suf[1]*m))*1.0/(2*suf[1]))>n) cout<<n;
    	else cout<<int(floor((suf[1]+sqrt(suf[1]*suf[1]+8*suf[1]*m))*1.0/(2*suf[1])));
    	fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		int r=i;
		while(sum<=m && r<=n){
			sum+=suf[r]*(r-i+1);
			r++;
		}
		maxn=max(maxn,r-i);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}