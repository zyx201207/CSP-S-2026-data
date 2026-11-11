#include <bits/stdc++.h>
using namespace std;
int n,cnt,num;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		num+=s[i];
		cin>>a;
		for(int i=0;i<n;i++){
			b+=a;
		}
	}
	for(int i=num/2;i<num;i++){
		if(b[i]!=b[num-i-1]){
			cnt++;
		}
		
	}
	
	cout<<cnt;
	return 0;
	 
}
