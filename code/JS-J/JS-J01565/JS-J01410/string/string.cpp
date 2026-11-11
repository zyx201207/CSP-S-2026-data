#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];
char b[1005];
string c;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		int t;
		char k;
		cin>>t>>k;
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			c+=b[i];
		}
	}
	int i=0,j=c.size()-1;
	int f=1;
	while(i!=j){
		if(c[i]!=c[j]){
			f=0;
			break;
		}
		i++;
		j--;
	}
	if(f==1){
		cout<<0;
	}
	cout<<c;
	return 0;
}
