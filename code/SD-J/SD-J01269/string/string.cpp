#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;
long long n,len;
int a[N];
char c[N];
long long ans=0;


int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len++;
	}
	long long l=1,r=len;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[r]>a[l]){
				ans+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}else{
				ans+=a[r];	
				a[l]=a[l]-a[r];
				r--;
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
	
	fclose(stdin);
	fclose(stdout);
}
