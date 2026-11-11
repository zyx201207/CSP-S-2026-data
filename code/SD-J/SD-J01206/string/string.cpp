#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[200005];
long long cnt=0;
char c[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			l++;
			r--;
		}else{
			if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				cnt+=a[l];
				l++;
				r--;
			}
		}
		
	}
	cout<<cnt;
	return 0;
} 
