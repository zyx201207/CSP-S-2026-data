#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,s;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				r--;
			}else if(a[l]<a[r]){
				l++;
			}else{
				r--;
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				s+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				s+=a[l];
				l++;
			}else{
				s+=a[r];
				r--;
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}