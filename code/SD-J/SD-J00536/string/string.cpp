#include <bits/stdc++.h>
using namespace std;
struct a{
	int x;
	char z;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int n;
	cin>>n;
	string s;
	int l=0,ls=0;
	char p;
	for(int i=0;i<n;i++){
		cin>>l;
		ls+=l;
		cin>>p;
		while(l>0){
			s=s+p;
			l--;
		}
	}
	long long int ans=0,b=0;
	if(ls%2==1){
		b=(ls-1)/2-1;
	}else{
		b=(ls-1)/2;
	}
	for(int i=0;i<=b;i++){
		if(s[i]!=s[ls-i-1]){
			ans++;
		}
	}
	cout<<ans;
	
	
	 
	return 0;
}
