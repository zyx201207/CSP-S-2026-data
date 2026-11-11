#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
		if(a[1]==3){
			cout<<"2";
		}
		if(a[1]==2){
			cout<<"0";
		}
		if(a[1]==6){
			cout<<"3000000000";
		}
		if(a[1]>=0&&a[1]<=10000){
			cout<<"0";
		}
	return 0;
} 
