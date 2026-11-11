#include<bits/stdc++.h>
using namespace std;
const int Q=3e5+5;
char ss[Q];
char ssk[Q];
long long ans=0;
char s[Q];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ans=0;
	long long n,m;
	cin>>n;
	long long index=0;
	long long num=0;
//	string s;
	long long len=0;
	for(int i=1;i<=n;i++){
		long long t;
		char c,mmmm;
		cin>>t>>c;
		len+=t;
		while(t--){
			s[index]=c;
			index++;
		}
	}
	//cout<<len;
	num=len; 
	//cout<<s;
	if(num%2==0){
		num=len/2;
		//string ss,ssk;
		for(int i=0;i<num;i++){
			ss[i]=s[i];
		}
		long long index_2=0;
		for(int i=num;i<len;i++){
			ssk[index_2]=s[i];
			index_2++; 
		} 
		for(int i=0;i<num;i++){
			if(ss[i]!=ssk[i]){
				ans++;
			}
		}//cout<<ss<<' '<<ssk; 
	}
	else {
		num=len/2+1;
		cout<<num;
		//string ss,ssk;
		for(int i=0;i<num-1;i++){
			ss[i]=s[i];
		}
		long long index_2=0;
		for(int i=num;i<len;i++){
			ssk[index_2]=s[i];
			index_2++; 
		} 
		for(int i=0;i<num-1;i++){
			if(ss[i]!=ssk[i]){
				ans++;
			}
		}
		//cout<<ss<<' '<<ssk; 
	}	
	cout<<ans;
	return 0;
}

