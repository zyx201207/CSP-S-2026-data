#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string shu="";
	long long n,sum=0,k=0;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		string c;
		cin>>a>>c;
		sum+=a;
		for(int j=0;j<a;j++){
			shu+=c;
		} 
	}
	k=0;
	long long x=sum/2+sum%2,cnt=0;
	for(int i=x;i<sum;i++){
		if(shu[i]!=shu[k]){
			cnt++;
		}
		k++;
	}
	cout<<cnt;
	return 0;
} 
