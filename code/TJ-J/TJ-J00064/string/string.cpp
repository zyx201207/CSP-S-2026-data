#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[200005];
	long long t=0;
	for(int i=1;i<=n;i++){
	cin>>a[i]; 
	string l;
    cin>>l;
	for(int j=1;j<=a[i];j++){
    b+=l;
	}
	}
	for(int i=1,j=n;i<=n/2,j>=n/2;i++,j--){
	if(b[i]!=b[j]){
	t++;
	}
	}
	cout<<t;
	return 0;
} 

