#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	long long arr[200000],num[200000],j=0,g;
	char ch[200000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>arr[i];
		cin>>ch[i];
	}
	string n[200000],m[200000];
	for(int i=0;i<a;i++){
		n[i]+=ch[i];
	}
	for(int i=a-1;i>=0;i--){
		m[i]+=ch[i];
	}
	for(int i=0;i<a;i++){
		if(n[i]!=m[i]){
			num[j]==i;
			j++;
			m[i]=n[i];
		}
	}
	for(int i=0;i<j-1;i++){
		longlong d=num[i];
		g+=arr[d];
	}
	cout<<g;
	fclose(stdin);
	fclose(stdout);
	return 0;
}