#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	char c;
	long long a;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
	}
	long long mid=s.size()/2;
	long long ans=0;
	long long v=s.size();
	if(v%2==0){
		long long j=mid-1;
		for(long long i=mid;i<v;i++){
			if(s[i]!=s[j]){
				ans++;
				s[i]=s[j];
			}
			j--;
		}
	}else if(v%2==1){
		long long j=mid-1;
		for(long long i=mid+1;i<v;i++){
			if(s[i]!=s[j]){
				ans++;
				s[i]=s[j];
			}
			j--;
		}
		
	}
	cout<<ans;
	return 0;
}
