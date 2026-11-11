#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],s,l,r;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				s+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++,r--;
			}
			else{
				s+=a[l];
				l++,r--;
			}
		}
		if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				s+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}
