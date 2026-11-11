#include<iostream> 
#include<vector> 
#include<cmath> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<cstdio>
#include<string> 
#include<cstring>
using namespace std;
int n;
int a[200005];
char c[200005];
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
		int l=0,r=n-1;
	while(l<=r){
		int ch=abs(a[l]-a[r]);
		if(c[l]==c[r]){
			if(ch==0) l++,r--;
			else if(a[l]>a[r]) a[l]=ch,a[r]=0,r--;
			else a[l]=0,a[r]=ch,l++;
			 
		}
		else{
			if(ch==0) ans+=a[l],l++,r--;
			else if(a[l]>a[r]) ans+=a[r],a[l]=ch,a[r]=0,r--;
			else ans+=a[l],a[l]=0,a[r]=ch,l++;
		}
	}
	cout<<ans;
	return 0;
}
