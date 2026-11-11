#include<bits/stdc++.h>
using namespace std;
long long n,a[200020],cnt;
char c[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]<=a[r]){
				cnt+=a[l];
				c[l]=c[r];
				a[r]-=a[l];
				l++;
				
			}
			else{
				cnt+=a[r];
				c[r]=c[l];
				a[l]-=a[r];
				r--;
				
			}
		}
		else{
			if(a[l]<=a[r]){
				l++;
				a[r]-=a[l];
			}
			else{
				r--;
				a[l]-=a[r];
			}
		}
	}
	cout<<cnt;
	return 0;
}

