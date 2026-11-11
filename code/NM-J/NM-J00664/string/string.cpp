#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a;
	long long s=0;
	for(int i=0;i<n;i++){
		int r;
		char id;
		cin>>r>>id;
		s+=r;
		for(int j=0;j<r;j++){
			a+=id;
		}
	}
	int ans=0;
	for(int i=0;i<s/2;i++){
		if(a[i]==a[s-i-1]){
			ans=0;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
