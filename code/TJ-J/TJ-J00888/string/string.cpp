#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int l=0,r=0,lp=0,rp=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	//cout<<l<<' '<<r<<endl;
	while(l<r){
		if(c[lp]==c[rp]){
			if(a[lp]==a[rp]){
				l+=a[lp];
				r-=a[rp];
				//cout<<1<<' '<<l<<' '<<r<<endl;
				lp++;
				rp--;
			}
			else if(a[lp]<a[rp]){
				l+=a[lp];
				r-=a[lp];
				//cout<<2<<' '<<l<<' '<<r<<endl;
				a[rp]-=a[lp];
				lp++;
			}
			else if(a[lp]>a[rp]){
				l+=a[rp];
				r-=a[rp];
			//	cout<<3<<' '<<l<<' '<<r<<endl;
				a[lp]-=a[rp];
				rp--;
			}
		}
		else{
			if(a[lp]==a[rp]){
				l+=a[lp];
				r-=a[rp];
			//	cout<<4<<' '<<l<<' '<<r<<endl;
				ans+=a[lp];
				lp++;
				rp--;
			}
			else if(a[lp]<a[rp]){
				l+=a[lp];
				r-=a[lp];
			//	cout<<5<<' '<<l<<' '<<r<<endl;
				a[rp]-=a[lp];
				ans+=a[lp];
				lp++;
			}
			else if(a[lp]>a[rp]){
				//cout<<16<<' '<<l<<' '<<r<<' '<<lp<<' '<<rp<<' '<<a[lp]<<' '<<a[rp]<<endl;
				l+=a[rp];
				r-=a[rp];
				a[lp]-=a[rp];
				ans+=a[rp];
				rp--;
				//cout<<26<<' '<<l<<' '<<r<<' '<<lp<<' '<<rp<<' '<<a[lp]<<' '<<a[rp]<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
