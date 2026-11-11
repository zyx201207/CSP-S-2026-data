#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0,ans=0;
char c; 	
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c; 
		sum+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long l=sum/2;
	ans=sum/2;
//	cout<<endl<<s<<endl<<sum<<endl<<l<<endl<<s[0]<<endl;
	for(long long i=0;i<l;i++){
		long long ch=sum-1-i;
		if(s[ch]==s[i]){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
