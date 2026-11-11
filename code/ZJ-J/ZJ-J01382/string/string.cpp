#include<bits/stdc++.h>
using namespace std;
map<int,long long>mp1;
map<int,char>mp2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;cin>>n;
	for(int i=1;i<=n;i++){
		long long x;cin>>x;
		char sx;cin>>sx;
		mp1[i]=x;
		mp2[i]=sx;
	}
	int l=1,r=n;
	while(l<r){
		if(mp2[l]!=mp2[r]){
			if(mp1[l]<mp1[r]){
				mp1[r]-=mp1[l];
				sum+=mp1[l];
				l++;
			}
			else if(mp1[l]>mp1[r]){
				mp1[l]-=mp1[r];
				sum+=mp1[r];
				r--;
			}
			else{
				sum+=mp1[l];
				l++;r--;
			}
		}else{
			if(mp1[l]<mp1[r]){
				mp1[r]-=mp1[l];
				l++;
			}
			else if(mp1[l]>mp1[r]){
				mp1[l]-=mp1[r];
				r--;
			}
			else{
				l++;r--;
			}
		}
	}
	cout<<sum;
	return 0;
}