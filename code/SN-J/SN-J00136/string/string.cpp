#include<bits/stdc++.h>
using namespace std;
int sum=0;
char m[501];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a,b=1;
	char c;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=b;j<=a+b;j++){
			m[j]=c;
		}
		b=b+a;
	}
	for(int i=0;i<=n/2;i++){
		if(m[i]!=m[n+1-i]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
