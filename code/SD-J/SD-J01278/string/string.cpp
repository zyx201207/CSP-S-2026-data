#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n,cnt1=1,cnt2=1,ans=0;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]<a[r]){
				cnt1+=a[l];
				cnt2+=a[l];
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else if(a[r]<a[l]){
				cnt1+=a[r];
				cnt2+=a[r];
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else{
				cnt1+=a[r];
				cnt2+=a[r];
				ans+=a[r];
				r--;
				l++;
			}
		}else{
			if(a[l]<a[r]){
				cnt1+=a[l];
				cnt2+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[r]<a[l]){
				cnt1+=a[r];
				cnt2+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				cnt1+=a[r];
				cnt2+=a[r];
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
