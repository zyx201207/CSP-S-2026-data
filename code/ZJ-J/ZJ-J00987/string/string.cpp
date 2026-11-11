#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long num;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			num+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];r--;
		}else{
			a[r]-=a[l];l++;
		}
	}
	cout<<num;
}
