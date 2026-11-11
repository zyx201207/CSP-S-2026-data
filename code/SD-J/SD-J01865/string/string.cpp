#include<iostream>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N],b[N],l,r,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c;
		b[i]=c-'a'+1;
	}
	l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(b[l]==b[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[l]==a[r]){
			if(b[l]!=b[r]){
				ans+=a[l];
			}
			l++,r--;
		}
		else{
			if(b[l]==b[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
