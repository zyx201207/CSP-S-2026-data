#include<iostream>
using namespace std;
const int N=2e5+10;
long long n,x,sum,a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[x++]=c[i];
		}
	}
	for(int i=0,j=x;i<j;i++){
		if(s[--j]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
