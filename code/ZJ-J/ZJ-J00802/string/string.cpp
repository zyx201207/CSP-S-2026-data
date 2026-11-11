#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=n,x=0,y=0;
	while(l<r){
//		if(x+a[l]>=sum/2){
//			if()
//		}
//		else if(y+a[r]>=sum/2){
//			if()
//		}
		if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
				continue;
			}
			else{
				ans+=a[l];
//				cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<ans<<"\n";
				a[r]-=a[l];
				l++;
			}
			x+=a[l];
		}
		else if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
				continue;
			}
			else{
				ans+=a[r];
//				cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<ans<<"\n";
				a[l]-=a[r];
				r--;
			}
			y+=a[r];
		}
		else{
			if(c[l]==c[r]&&l!=r){
				l++,r--;
			}
			else{
				ans+=a[l];
//				cout<<l<<" "<<r<<" "<<ans<<"\n";
				l++,r--;
			}
			x+=a[l];
			y+=a[r];
		}
	}
	cout<<ans;
	return 0;
}

