#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	string S;
	int L=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			S[L]=c[i];
			L++;
		} 
	}
	for(int l=0;l<=(L-1)/2;l++){
		if(S[l]!=S[L-l]){
			sum++;
		}
	}
	cout<<sum;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
