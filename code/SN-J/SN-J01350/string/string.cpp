#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int number;
	char c;
	while(n--){
		cin>>number>>c;
		for(int i=1;i<=number;i++){
			s=s+c;
		}
	}
	s="!"+s;
	long long len=s.size()-1;
	long long cnt=0;
	if(cnt%2!=0){//ÆæÊý 
		 long long mid=(1+len)/2;
		 for(long long i=1;i<mid;i++){
		 	if(s[i]!=s[len+1-i]) cnt++;
		 }
		 cout<<cnt;
	}
	else{
		long long point =len/2;
		for(long long i=1;i<=point;i++){
			if(s[i]!=s[len+1-i]) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
/*
3
2 a
2 b
1 c
*/
