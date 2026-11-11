#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n,a[N],sum,l=1,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else{
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}