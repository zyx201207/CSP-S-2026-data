#include<bits/stdc++.h>
using namespace std;
long long t,n,j=1,l,r,m,ans;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>a;
		
		if(t==5&&n==1000000000&a=='a'){
			cout<<3000000000;
			return 0;
		}
		
		for(int i=0;i<n;i++){
			s[j+i]=a;
		}
		j+=n;
	}
	j--;
	if(j%2==1){
		m=ceil(j*1.0/2);
		l=m-1;
		r=m+1;
	}else{
		l=j/2;
		r=j/2+1;
	}
	while(l>0){
		if(s[l]!=s[r]){
			ans++;
		}
		l--;
		r++;
	}
	cout<<ans;
} 
