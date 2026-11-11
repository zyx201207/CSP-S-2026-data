#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freoprn("string.out","w",stdout);
	int n;
	cin>>n;
	string b;
	long long a[n];
	char m;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>m;
		for(long long j=0;j<a[i];j++){
			b += m;
		}
	}
	long long c=0,d=n,e=0;
	while(e<d){
		if(b[e]==b[d]){
			e++;
			d--;
		}
		else{
			c++;
			e++;d--;
		}
	}
	cout<<c;
	fclose(stdin);
	flcose(stdout);
	return 0;
}