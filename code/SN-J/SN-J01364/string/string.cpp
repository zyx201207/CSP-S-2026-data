#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				num+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				num+=a[l];
				l++;
			}else{
				num+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<num;
} 
