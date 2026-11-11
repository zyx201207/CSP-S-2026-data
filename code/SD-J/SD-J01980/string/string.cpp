#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string x;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	long long ans=0;
	while(true){
		if(l>r) break;
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[l];
				r--;
				l++;
			}
			else{
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
