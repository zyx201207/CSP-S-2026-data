#include<bits/stdc++.h>
using namespace std;
long long n;
long long a,sum=0;
char c[1000000];
bool j=true;
string s;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c[i];
	}
	for(int i=0;i<n-1;i++){
		if(c[i]!=c[i+1]){
			j=false;
		}
	}
	if(j==true){
		cout<<0;
	}
	else{
		cout<<sum/2;
	}
	return 0;
}
