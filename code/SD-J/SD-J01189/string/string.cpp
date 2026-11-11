#include<bits/stdc++.h>
using namespace std;
const unsigned long long MAXN=2*1e5+5;
unsigned long long a[MAXN],n=0,mxn=0,s=0;
char b[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mxn+=a[i];
	}
 	if(n==1){
		cout<<0;
		return 0;
	}
	if(mxn%2==1){
		unsigned long long l=1,r=n;
		while(l!=r){
			if(b[l]==b[r]){
				if(a[l]>a[r]){
					a[l]=a[l]-a[r];
					r--;
				}
				else if(a[r]>a[l]){
					a[r]=a[r]-a[l];
					l++;
				}
				else if(a[l]==a[r]){
					r--;
					l++;
				}
			}
			else{
				if(a[l]>a[r]){
					s+=a[r];
					a[l]=a[l]-a[r];
					r--;
				}
				else if(a[r]>a[l]){
					s+=a[l];
					a[r]=a[r]-a[l];
					l++;
				}
				else if(a[r]==a[l]){
					s+=a[l];
					l++;
					r--;
				}
			}
		}
	}
	else{
		unsigned long long l=1,r=n;
		while(l<r){
			if(b[l]==b[r]){
				if(a[l]>a[r]){
					a[l]=a[l]-a[r];
					r--;
				}
				else if(a[r]>a[l]){
					a[r]=a[r]-a[l];
					l++;
				}
				else if(a[l]==a[r]){
					r--;
					l++;
				}
			}
			else{
				if(a[l]>a[r]){
					s+=a[r];
					a[l]=a[l]-a[r];
					r--;
				}
				else if(a[r]>a[l]){
					s+=a[l];
					a[r]=a[r]-a[l];
					l++;
				}
				else if(a[r]==a[l]){
					s+=a[l];
					l++;
					r--;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
/*
3
2 a
2 b
1 c


2


2
2 a
3 a


0
Trick||Treat!
*/
