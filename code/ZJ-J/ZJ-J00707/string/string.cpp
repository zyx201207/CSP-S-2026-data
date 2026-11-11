#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z,s;
char c;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c; 
		b+=c;
	} 
	int i=0,j=n-1;
	while(i<=j){
		if(a[i]>a[j]){
			a[i]-=a[j];
			s=a[j];
			j--;
		}else if(a[i]<a[j]){
			a[j]-=a[i];
			s=a[i];
			i++;
		}else{
			s=a[i];
			i++;
			j--;
		}
		if(b[i]!=b[j]){
			z+=s;
		}

	}
	cout<<z;
	return 0;
}


