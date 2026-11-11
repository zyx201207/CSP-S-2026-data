#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,s;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	r=n;
	l=1;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				a[r]-=a[l++];
			}
			else if(a[r]==a[l]){
				l++;
				r--;
			}
			else{
				a[l]-=a[r--];
			}
		}
		else{
			if(a[l]==a[r]){
				s+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l++];
			}
			else{
				s+=a[r];
				a[l]-=a[r--];
			}
		}
	}
	cout<<s;
	return 0;
}
