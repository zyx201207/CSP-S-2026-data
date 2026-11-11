#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
	}
	int length=0;
	int a[10005];
	char s[100005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		length+=a[i];
		
	}
	string z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			z+=s[i];
		}
		
	}
	int sum=0;
	if(n==2){
		if(s[1]==s[2]){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]);
		}
	}else{
		for(int i=1;i<=length/2;i++){
			if(s[i]!=s[length-i+1]){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
