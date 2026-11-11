#include<bits/stdc++.h>
using namespace std;
long long a[500050],m,w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		long long dai=1,mid=(l+r+1)/2,mm=m;
		for(int i=mid-1;i>=1;i--){
			if(a[i]+mm>=a[mid]){
				dai++;
				mm-=(a[mid]-a[i]);
			}
			else{
				break;
			}
		}
		if(dai==mid){
			l=mid;
		}
		else{
			r=mid-1;
		}
		for(int i=mid+1;i<=n;i++){
			if(a[i]==a[i-1]){
				dai++;
			}
			else{
				break;
			}
		}
		w=max(w,dai);
	}
	cout<<w;
	return 0;
}
