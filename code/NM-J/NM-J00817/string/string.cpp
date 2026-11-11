#include<bits/stdc++.h>
using namespace std;
int n,a;
long long cnt1;
string s ,b;
long long c(string s,int cnt){
	int x=cnt/2+1;
	long long w=0;
	for(int i=0,j=cnt;i<=x&&j>=x;i++,j--){
		if(s[i]!=s[j-1]){
			s[j-1]=s[i];
			w++;
		}
	}
	return w;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		cnt1+=a;
		for(int j=0;j<a;j++){
			s+=b;
		} 
	}
	cout<<c(s,cnt1);
	return 0;
}
