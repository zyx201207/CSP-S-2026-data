#include<bits/stdc++.h>
using namespace std;
const long long h=1e5*5+5,f=1e12+1;
long long m,a[h],b[h],minnum[2][2],ans=1;
bool cmp(long long x,long long y){
	return x<y;
}
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long ans;
	cin>>c>>t;
	for(int i=1;i<=c;i++){
		int n,k;
		for(int j=1;j<n;j++){
			cin>>a[j]>>b[j];
		}
		if(ans<0){
			ans=-ans;
		}
		if(ans>n){
			ans%=n;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
