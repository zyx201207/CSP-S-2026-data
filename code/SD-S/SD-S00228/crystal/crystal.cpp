#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],ans,maxans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=a[1]-a[i];
		//cout<<c[i];
	}
	//cout<<"\n";
	long long top=1,x=0;
	for(int i=1;i<=n;i++){
		x+=c[i]-c[top];
			ans++;
		
		if(x>m){
			while(x>m) {
				top++;
				ans--;x-=(c[top]-c[top-1])*ans;
				
			}
		}
		//cout<<x<<"  "<<ans<<" ";
		maxans=max(maxans,ans);
	} cout<<maxans;
	return 0;
}//Oct31==Dec25?
