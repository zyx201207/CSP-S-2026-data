#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,p=0,s=0,ans=1;
	cin>>n>>m;
	int a[n+100];
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(i=1;i<n;i++){
		s+=(i-p)*(a[i]-a[i-1]);
		while(s>m){
			s-=(a[i]-a[p]);
			p++;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
