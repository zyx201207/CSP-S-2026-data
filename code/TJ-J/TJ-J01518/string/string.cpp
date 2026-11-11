#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long sum=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				sum+=a[r];
			}			
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]){
				sum+=a[r];
			}
			l++;
			r--;
		}else{
			if(c[l]!=c[r]){
				sum+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<sum;
	return 0;
}
