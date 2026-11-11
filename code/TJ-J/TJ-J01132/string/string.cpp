#include<bits/stdc++.h>
using namespace std;
struct str{
	long long len;
	char c;
}s[20];
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long cnt=0;
	long long num=1;
	cin >> n;
	//问题：时间过长 
	for(int i=1;i<=n;i++){
		cin >> s[i].len >> s[i].c;
		long long num1=num;
		num1--;
		for(long long j=num;j<=s[i].len+num1;j++){
			st[j]=s[i].c;
			num++;
		}
	}
	num--;
	long long l=1,r=num;
	while(l<=r){
		if(st[l]!=st[r]){
			st[r]=st[l];
			cnt++;
		}
		l++,r--;
	}
	cout << cnt;
	return 0;
} 
