#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long T;
	cin>>T;
	long long a,cc=0,ans=0;
	char a1;
	vector<char>b;
	while(T--){
		cin>>a>>a1;
		cc+=a;
		for(long long i=0;i<a;i++){
			b.push_back(a1);
		}
	}
	long long l=cc-1,r=0;
	long long aa=(cc-1)/2;
	while(aa--){
		if(b[r]==b[l]){
			l--;
			r++;
		}
		else{
			ans++;
			l--;
			r++;
		}
	}
	cout<<ans;
	return 0;
} 


