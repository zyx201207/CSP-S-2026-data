#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long c=0;
	while(l<=r){
		if(a[l]<=0){
			l++;
		}
		if(a[r]<=0){
			r--;
		}
		if(b[l]!=b[r]&&l<=r){
			c++;
		}
		a[l]--;
		a[r]--;
	}
	cout<<c<<endl;
	return 0;
}
