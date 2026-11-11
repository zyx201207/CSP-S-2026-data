#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20005],len=0,sum=0;
	string c[20005],S;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			S+=c[i];
		}
	}
	for(int i=0;i<len/2;i++){
		if(S[i]!=S[len-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
