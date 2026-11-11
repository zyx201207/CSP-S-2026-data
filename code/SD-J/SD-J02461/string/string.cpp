#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int  n;
	cin>>n;
	string b="";
	char c[20020];
	long long a[20020];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long count=1;
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			count=a[l];
			a[l]=1;
			a[r]=1;
		}
		l++;
		r--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b+=c[i];
		}
	}
	long long le=0;
	long long re=b.length()-1;
	long long ans=0;
		while(le<re){
		if(b[le]!=b[re]){
			ans++;
		}
		le++;
		re--;
	}
	cout<<ans*count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
