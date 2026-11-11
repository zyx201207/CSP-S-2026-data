#include<bits/stdc++.h>
using namespace std;
long long n,j=0;
string str;
int check(){
	long long ans=0;
	for(long long i=0;i<=j/2;i++){
		if(str[i]!=str[j-i]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long l;
		char ch;
		cin>>l>>ch;
		while(l--){
			str[j]=ch;
			j++;
		}
	}
	j--;
	cout<<check();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
