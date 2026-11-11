#include<bits/stdc++.h>
using namespace std;
long long a[200050];
char c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0,l=1,r=n,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r])cnt+=a[l],a[r]-=a[l],l++;
			else if(a[l]>a[r])cnt+=a[r],a[l]-=a[r],r--;
			else cnt+=a[l],l++,r--;
		}
		else{
			if(a[l]<a[r])a[r]-=a[l],l++;
			else if(a[l]>a[r])a[l]-=a[r],r--;
			else l++,r--;
		}	
	}
	cout<<cnt;
	return 0;
}