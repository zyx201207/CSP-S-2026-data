#include<bits/stdc++.h>
using namespace std;
int n,len;
int sum;
int mx=-100;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=len;j<x+len;j++){
			s[j]=a;
		}
		len+=x;
	}
	if(len%2==0){
		for(int i=0;i<=len/2;i++){
			if(s[i]!=s[len-i]){
				sum++;;
			}
		}
		mx=max(mx,sum);
		sum=0;
	}else{
		for(int i=0;i<len/2+1;i++){
			if(s[i]!=s[len-i-1]){
				sum++;
			}
		}
		mx=max(mx,sum);
	}
	cout<<mx<<endl;
	return 0;
}

