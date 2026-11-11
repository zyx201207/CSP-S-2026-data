#include<iostream>
using namespace std;
const int N=2e5+10;
long long n,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
