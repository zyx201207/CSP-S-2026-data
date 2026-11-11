#include<bits/stdc++.h>
using namespace std;
struct q{
	int num;
	char zf;
};
q n[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	string m;
	for(int i=0;i<a;i++){
		cin>>n[i].num;
		cin>>n[i].zf;
		for(long long j=1;j<=n[i].num;j++){
			m+=n[i].zf;
		}
	}
	long long cha=2;
	long long size=m.size()/2;
	if(m.size()%2==0){
		cha=1;
	}
	long long num=0;
	for(long long i=size;i>=1;i--){
		if(m[i-1]!=m[i-1+cha]){
			num++;
		}
		cha+=2;
	}
	cout<<num;
	return 0;
}
