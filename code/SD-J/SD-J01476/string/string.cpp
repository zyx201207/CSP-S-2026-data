#include <bits/stdc++.h>
using namespace std;
long long n,a[2*100005],l=1,r,cnt,k; 
char c[2*100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(c[l]==c[r]){
		    if(a[l]<a[r]){
		    	a[r]-=a[l];
		    	l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}else{
				a[l]-=a[r];
				r--;
			}
			continue;
		}
		if(a[l]>a[r]){
			cnt+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			cnt+=a[l];
			l++;
			r--;
		}else{
			cnt+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<cnt;
	return 0;
} 
