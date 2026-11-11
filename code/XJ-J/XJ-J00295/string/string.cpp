#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		string a;
		cin>>a;
		while(x--){
			str+=a;
		}
	}
	long long int len=str.size();
	long long ans=0;
	string hw=str.substr(0,len/2);
	string h=str.substr(len/2,len);
	cout<<hw<<" "<<h<<endl;
	for(long long i=0,j=len/2-1;i<len/2,j>=0;i++,j--){
		if(hw[i]!=h[j]){
			ans++;
		}
	}
	cout<<ans;
	//aabbcc
	
	return 0;
}
