#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string k="";
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char b;
		cin>>b;
		for(int i=1;i<=a;i++){
			k+=b;
		}
	} 
	int len=k.length();
	int ans=0;
	for(int i=1;i<=len;i++){
		int l=1,r=len-1;
		while(l<r){
			if(k[l]==k[r]){
				l++;
				r--;
			}else{
				k[l]=k[r];
				ans+=2;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
