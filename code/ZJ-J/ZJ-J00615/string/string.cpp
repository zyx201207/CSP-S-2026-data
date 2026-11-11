#include<bits/stdc++.h>
using namespace std;
#define MAX int(2e5+1000)
int n;
int a[MAX];
char c[MAX];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	int dele=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;	
			}else{
				ans+=a[l];
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
