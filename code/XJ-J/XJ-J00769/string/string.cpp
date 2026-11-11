#include<bits/stdc++.h>
using namespace std;
int n; 
const int N=2e5+10;
struct huiweng{
	long long a;
	char c;
	
}arr[N];
long long cs=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool f=0;
	
	cin >>n;
	
	cin>>arr[1].a>>arr[1].c;
	long long sum=0;
	sum+=arr[1].a;
	for(int i=2;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		sum+=arr[i].a;
		if(arr[i].c!=arr[i-1].c){
			f=1;
		}
		
	}
	
	
	if(n==1){
		cout<<0;
		return 0;
	}
	if(f!=1){
		cout<<0;
		return 0;
	}
	long long dyt;
	if(sum%2==0){
		dyt=sum/2;
		
	}else{
		dyt=(sum/2)+1;
	}
	string s;
	for(long long i=1;i<=n;i++){
		while(arr[i].a--){
			s+=arr[i].c;
		}
	}
	string s1=s.substr(0,dyt),s2=s.substr(dyt,sum-dyt);
	string s3=s1.substr(0,s2.size()-1);
	reverse(s3.begin(),s3.end());
	
	for(long long i=0;i<s2.size();i++){
		if(s3[i]!=s2[i]){
			cs++;
		}
	}
	cout<<cs;
	return 0;
} 
