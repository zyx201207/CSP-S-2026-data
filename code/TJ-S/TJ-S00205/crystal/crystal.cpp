#include<bits/stdc++.h>
using namespace std;
#define int long long
int f,r,n,m,a[500005],maxn=-1e18,now,pre,maxl,ji,l,ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=maxn-a[i];
		
	}
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}*/
	f=r=1;ji=m;
	while(r<=n){
		//cout<<ji<<" "<<r<<endl;
		if(ji>=a[r]-a[f]){
			if(r==n){
				maxl=max(maxl,r-f+1);
			}
			ji-=a[r]-a[f];r++;
		}
		else{
			maxl=max(maxl,r-f);
			//cout<<"!"<<r<<""<<ji<<endl;
			if(ji>a[f+1]){
				ji+=(r-f)*(a[f+1]-a[f]);
			}
			else {
				ji+=(r-f-1)*(a[f+1]-a[f]);
			}
			f++;
		}
		
	}
	cout<<maxl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
