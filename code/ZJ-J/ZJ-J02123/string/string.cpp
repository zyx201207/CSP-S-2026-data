#include<bits/stdc++.h>
using namespace std;
long long n,t,p,s,i,j;
char c;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t>>c;
		for(j=p;j<p+t;j++){
			a[j]=c;
		}
		p+=t;
	}
	j=p-1;
	for(i=0;i<j;i++){
		if(a[i]!=a[j]){
			s++;
		}
		j--;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}