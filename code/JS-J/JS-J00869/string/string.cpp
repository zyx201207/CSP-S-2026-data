#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long arr[n],len=0;
	char ch[n];
	string a;
	for(int i=0;i<n;i++){
		cin>>arr[i]>>ch[i];
		len+=arr[i];
		for(int j=0;j<arr[i];j++){
            a+=ch[i];
		}
	}
	int count=0;
	if(len%2==0){
        for(int i=0;i<len/2;i++){
            if(a[i]!=a[len-i-1])count++;
        }
	}else{
        for(int i=0;i<len/2;i++){
            if(a[i]!=a[len-i-1])count++;
        }
	}
	cout<<count<<endl;
	return 0;
}
