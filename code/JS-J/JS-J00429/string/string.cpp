#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<=r){
		if(a[l]>a[r]){
			if(s[l]!=s[r]){
				a[r]=a[r]-a[l];
				while(a[r]<=0){
					r--;
					a[r]+=a[r+1];
				}
				cnt+=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[l]<a[r]){
			if(s[r]!=s[l]){
				a[l]=a[l]-a[r];
				while(a[l]<=0){
					l++;
					a[l]+=a[l-1];
				}
				cnt+=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(s[l]!=s[r]) cnt+=a[l];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
