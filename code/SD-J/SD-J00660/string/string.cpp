#include<bits/stdc++.h>
using namespace std;
long long n,z=0,l=0,k=0,j=0;
char a;
char c[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int w=0;w<n;w++){
		cin>>l>>a;
		for(int e=0;e<l;e++){
			c[z]=a;
			z++;
		}
	}
	for(int w=0;w<z/2;w++){
		if(c[w]!=c[z-j-1]){
			k++;
		}
		j++;
	}
	cout<<k;
	return 0;
}
