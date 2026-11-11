#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int l=1,r=n;
	long long q=0;
	while(l<r){
		if(s[l]==s[n]){
			if(a[l]>a[r]) a[l]-=a[r],r--;
			else if(a[l]<a[r]) a[r]-=a[l],l++;
			else a[l]=0,a[r]=0,l++,r--;
		}
		else{
			if(a[l]>a[r]) a[l]-=a[r],q+=a[r],r--;
			else if(a[l]<a[r]) a[r]-=a[l],q+=a[l],l++;
			else q+=a[l],a[l]=0,a[r]=0,l++,r--;
		}
	}
	cout<<q;
	return 0;
}
