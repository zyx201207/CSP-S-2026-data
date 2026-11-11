#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k=0;
	cin>>n;
	string s1;
	for(long long i=0;i<=n-1;i++){
		long long a;
		string s;
		cin>>a;
		cin>>s;
		for(long long j=1;j<=a;j++){
			s1+=s;
		}
	}
	long long x=0,y=s1.size()-1,cnt=0;
	while(x<y){
		if(s1[x]!=s1[y]){
			s1[x]=s1[y];
			cnt++;
		}
		x++;
		y--;
	}
	cout<<cnt;
	return 0;
}
