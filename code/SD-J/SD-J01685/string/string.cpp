#include<bits/stdc++.h>
using namespace std;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,a;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			st[num+j]=b;
			num++;
		}
	}
	long long l=0,sum=0;
	long long e=num;
	while(l>e){
		if(st[l]==st[e]){
		l++;
		e--;
	}
	else{
		sum++;
	}
	}
	cout<<sum;
	return 0;
}
