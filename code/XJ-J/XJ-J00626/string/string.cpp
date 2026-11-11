#include<bits/stdc++.h>
using namespace std;
	string str;
	int arr[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cin>>ch;
		str+=ch;
	}
	long long s=0;
	int c=str.size();
	if(n%2!=0){
		for(int i=1;i<=c/2;i++){
			if(str[i-1]!=str[c-i-1]){
				s+=arr[i];
			}
		}
	}else{
		for(int i=1;i<=c/2+1;i++){
			if(str[i-1]!=str[c-i-1]){
				s+=arr[i];
			}
		}
	}
	cout<<s;
	
	return 0;
}