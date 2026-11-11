#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long n,x;
long long sum=0;
char c,s[N];
bool hw(char a[N],long long len){
	for(long long i=1;i<=len/2+1;i++){
		if(a[i]!=a[len-i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=1;
	while(n--){
		cin>>x>>c;
		for(long long i=cnt;i<x+cnt;i++){
			s[i]=c;
		}
		cnt=x+cnt;
	}
	cnt--;
	long long i=1;
	while(1){
		if(hw(s,cnt)){
			break;
		}
		s[i]=s[cnt+1-i];
		i++;
		sum++;
	}
	cout<<sum;
	return 0;
}