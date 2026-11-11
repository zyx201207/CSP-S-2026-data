#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		char b;
		cin>>c>>b;
	while(c){
		a.push_back(b);
		c--;
	}
	}
	int m=a.size(),j=0,sum=0;
	int min=(m+1)/2;
	for(int i=m-1;i>min-1;i--){
		if(a[i]!=a[j]){
			sum++;
			j++;
		} 
		}
		cout<<sum;
	fclose(stdin);
	fclose(stdout);
return 0;
} 
