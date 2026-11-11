#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,sum=0;
	string b;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[cnt]>>b[cnt];
		cnt++;
	}
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	int l=0,r=cnt-1,ans=0;
	while(l<r){
		if(b[l]!=b[r]){
			ans++;
		}
		a[l]--;
		a[r]--;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
