#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans=0;
string s,aa[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>aa[i];
	for(int i=0;i<n;i++) {
		for(int j=1;j<a[i];j++){
			aa[i]+=aa[i];
		} 
		s+=aa[i];
	}
	int len=s.size();
	if(len%2==0){
		for(int i=1;i<=len/2;i++){
			for(int j=len;j>len/2;j++){
				if(aa[i]!=aa[j]) ans++;
				
			}
		}
	} 
	else{
		for(int i=1;i<len/2;i++){
			for(int j=len;j>len/2+1;j--){
				if(aa[i]!=aa[j]) ans++;
				cout<<ans;
			}
		}
	}
	cout<<ans;
	return 0;
} 
