//SN-S00461 高子修 西安市第六中学 
/* why j and s the fourth all wa???
 * 
 */
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long mn[500005];
long long mnn[500005];
//long long qzh[500005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
//	long long d; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		qzh[i]=qzh[i-1]+a[i];
	}
	long long d=a[2]-a[1];
	bool yes=1;
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i]!=d){
			yes=0;
			break;
		}
	}
	if(yes){
		long long xxx=m/d;
		cout<<2*xxx-1;
		return 0;
	}
	sort(a+1,a+1+n);
	int anss=0;
	for(int i=1;i<=n;i++){
		int mm=m;
		int ans=0;
		for(int j=1;j<=i;j++)mn[j]=a[i]-a[j];
		sort(mn+1,mn+1+i);
		for(int j=1;j<=i;j++){
			mm-=mn[j];
			if(mm>=0)ans++;
			else break;
		}
//		cout<<ans<<"\n";
		anss=max(ans,anss);
	}
	
//	sort(mnn+1,mnn+1+n,cmp);
	cout<<anss;
	return 0;
}
