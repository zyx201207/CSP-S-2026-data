#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N],cnt;
char c[N];
long long l,r,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(1){
		if(l==r||l-1==r){
			break;
		}
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}
		}
		else if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++,r--;
			}
			else{
				cnt+=a[r];
				l++,r--;
			}
		}
		else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[r]-=a[l];
				cnt+=a[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
