#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c[100000];
	int j=0;
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		while(x--){
			c[j]=a;
			j++;
		}
	}
	int sum=0;
	for(int i=0;i<j/2;i++){
		if(c[i]!=c[j-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
