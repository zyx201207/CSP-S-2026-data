//xingming:tiehanqing kaohao:SN-J00777 xuexiao:shanxiyananzhongxue
#include<bits/stdc++.h>
using namespace std;
struct chars{
	int len;
	string cha;
};
chars a[200020];
string mid,al;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","out",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].cha;
		for(int j=0;j<a[i].len;j++){
			al+=a[i].cha;
		}		
	}int b=0;
	long long o=0;
	if(n%2==1)b=1;
	if(b)mid=a[n/2+1].cha;
	for(int i=0;i<n/2;i++){
		if(al[n/2-1-i] != al[(n-1)/2+i+1])o++;
	}cout<<o;
	return 0;
}
