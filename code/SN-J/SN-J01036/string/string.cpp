#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	int n,l=0,cnt=0,ans;
	int b[200000];
	string c;
    char s[10000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c[i-1];
		b[i-1]=a;
	} 
	for(int i=1;i<=n;i++){
		l+=b[i-1];
		ans=b[i-1];
		for(int j=0;i<ans;j++){
			s[l-ans+j]=c[i-1];
			
		} 
	} 
	for(int i=0;i<l/2;i++){
		if(s[i] = s[l]+1-i){
			cnt++;
		}
	} 
	if(l%2==0){
		cout<<l-cnt;
	}else{
		cout<<l-cnt-1;
	}
	
	return 0;
}

