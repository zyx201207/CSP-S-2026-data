#include<bits/stdc++.h>
using namespace std;
bool hw(char a[],long long b){
	long long i=1,j=b;
	for(;i<=b/2,j>=b-b/2;i++,j--){
		if(a[i]!=a[j]){
			return false;
		}
	}
	return true;
}
int main(){
#define int long long
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[1000000]={};
	char c[1000000]={};
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	char b[num+1]={};
	int q=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[q]=c[i];
			q++;
		}
	}
	if(hw(b,num)){
		cout<<0;
		return 0;
	}
	int h=num/2;
	char d[h+1]={};
	for(int i=1;i<=h;i++){
		d[i]=b[i];
	}
	int sum=0;
	for(int i=num-h,j=h;i<=num,j>=1;i++,j--){
		if(d[j]!=a[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
