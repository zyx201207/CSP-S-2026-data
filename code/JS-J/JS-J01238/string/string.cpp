#include<bits/stdc++.h>
using namespace std;
long long n,c=0;
int a[1000005];
char b[1000005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];	
	}
	for(int i=0;i<n/2-1;i++){
		for(int j=n-1;j>=n/2;j--){
			if(b[j]!=b[i])c=c+(a[i]/2)+(a[j]/2);
			else{
				if(a[i]>a[j]) c=c+a([i]/2);
				else c=c+(a[j]/2)
			}
		}
		
	}
	cout<<c;
}
