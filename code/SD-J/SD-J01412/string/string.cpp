#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,r=1,l,cnt;
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=n;
	while(r<l){
		if(c[r]==c[l]){
			if(a[r]==a[l]){
				r++;
				l--;
			}else if(a[r]>a[l]){
				a[r]-=a[l];
				l--;
			}
			else if(a[r]<a[l]){
				a[l]-=a[r];
				r++;
			}
		}else{
			if(a[r]==a[l]){
				cnt+=a[r];
				r++;
				l--;
			}else if(a[r]>a[l]){
				cnt+=a[l];
				a[r]-=a[l];
				l--;
			}
			else if(a[r]<a[l]){
				cnt+=a[r];
				a[l]-=a[r];
				r++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
