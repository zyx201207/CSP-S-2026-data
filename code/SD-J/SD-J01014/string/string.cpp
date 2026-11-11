#include<bits/stdc++.h>
using namespace std;
char b[200001];
long long a[200001],n,sum=0,ans=0,l=1,r;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	r=n;
	while(l!=r){
		if(a[l]>a[r]){
			if(b[l]==b[r]){
				a[l]-=a[r];
				r--;
		}
			else {
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(b[l]==b[r]){
				a[r]-=a[l];
				l++;
		}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
