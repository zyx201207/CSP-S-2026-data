#include<bits/stdc++.h>
using namespace std;
char s[100000009];
char s2[100000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,top=0,k1;
	cin>>n;
	for(int i=0;i<n;i++){
		int k=0;
		cin>>k;
		char x;
		cin>>x;

		for(int j=0;j<k;j++){	
			s[i+j+1]=x;
			sum++;
		}
		
	}
	for(int i=sum-1;i>=0;i--){
		s2[i]=s[sum-i+1];
	}
	for(int i=0;i<sum;i++){
		if(s[i]!=s2[i]){
			top++;
		}
	}
	cout<<top%2==0?top/2+1:top/2;
	return 0;
}
