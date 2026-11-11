#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string a="";
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		char in;
		cin>>in;
		for(int i=1;i<=num;i++){
			
			a+=in;
		}
	}
	long long ans=0;
	long long l=0,r=a.size()-1;
	while(l<r){
		if(a[l]!=a[r]){
			ans+=1;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
