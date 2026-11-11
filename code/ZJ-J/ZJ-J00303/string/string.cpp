#include<bits/stdc++.h>
using namespace std;
int n,r,a[200005];
unsigned long long sum;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int l=1;l<=n;l++){
		while(r>l){
			if(b[r]==b[l]){
				if(a[r]>=a[l]){
					a[r]-=a[l];
					break;
				}
				else{
					a[l]-=a[r];
					r--;
				}
				continue;
			}
			if(a[r]>=a[l]){
				sum+=a[l];
				a[r]-=a[l];
				break;
			}
			else{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
