#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long size=0;
	for(int i=0;i<n;i++){
		size+=a[i];
	}
	long long cnt=0;
	for(long long i=0;i<size/2;i++){
		//获取第i个和第size-i-1个字符
		char c1,c2;
		long long daichu=i;
		long long j=0;
		while(daichu-a[j]>0){
			daichu-=a[j];
			j++;
		}
		c1=c[j];
		daichu=size-i;
		j=0;
		while(daichu-a[j]>0){
			daichu-=a[j];
			j++;
		}
		c2=c[j];
		//计算 
		if(c1!=c2){
			cnt++;
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
