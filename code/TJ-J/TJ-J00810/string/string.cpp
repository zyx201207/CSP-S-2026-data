#include<bits/stdc++.h>
using namespace std;
char s[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,cnt=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i]=x;
		s[i]=c;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				cnt+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				r--;
			}
			else if(a[l]<a[r]){
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
