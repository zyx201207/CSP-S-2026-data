#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
long long ans,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(b[l]==b[r]){
			int mi=min(a[l],a[r]);
			a[l]-=mi,a[r]-=mi;
		}
		else{
			int mi=min(a[l],a[r]);
			a[l]-=mi,a[r]-=mi;
			ans+=mi;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
