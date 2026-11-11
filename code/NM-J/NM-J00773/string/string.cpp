#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a;
	long long n,num,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>a;
		for(int j=1;j<=num;j++){
			s+=a; //s=1
		}
	}
	long long len=s.size();
	long long l=0;
	long long r=len-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}//

