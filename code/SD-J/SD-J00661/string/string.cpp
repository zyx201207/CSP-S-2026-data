#include<bits/stdc++.h>
using namespace std;
int const N=1e7;
long long n;string str1="";
long long a[N];char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2&&b[1]!=b[2]){
		cout<<min(a[1],a[2]); return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			str1+=b[i];
	}
	string str2="",str3=str1;
	for(int i=str1.size()-1;i>=0;i--)
		str2+=str1[i];
	if(str1==str2){
		cout<<0;
		return 0;
	}	
	int cnt=0;
	for(int i=0;i<=(str1.size()-1)/2;i++){
		if(str3[i]!=str3[str3.size()-1-i]){	
			str3[i]=str3[str3.size()-1-i];cnt++;
		}
		
	}
	cout<<cnt;//二分找左边界真忘了 ，还是办了吧,也有可能是深搜或者DP 
	return 0;
}
//10
