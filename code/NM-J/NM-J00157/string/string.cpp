#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout); 
	long long n=0,l=0,k=0
	int a[20005];
	char c[20005];
	string S;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=0;j<a[i];j++)S+=c[i];
	}
	
	cout<<S<<endl;
	return 0;
}
