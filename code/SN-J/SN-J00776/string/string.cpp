//姓名:张泽凯,考号:SN-J00776,学校:西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
string a="",z="";
bool xd=1;
long long js=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		char zf;
		cin>>c>>zf;
		for(int i=1;i<=c;i++)a+=zf;
		z+=zf;
	}
	long long j=a.size()-1;
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[j])++js;
		--j;
	}
	cout<<js;
	return 0;
}
