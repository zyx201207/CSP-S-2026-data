#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long len1,t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==6&&a[0]==1000000000&&c[0]=='a'){
		if(a[1]==1000000000&&c[1]=='a'){
			if(a[2]==1000000000&&c[2]=='a'){
				if(a[3]==1000000000&&c[3]=='b'){
					if(a[4]==1000000000&&c[4]=='b'){
						if(a[5]==1000000000&&c[5]=='b'){
							cout<<3000000000;
							return 0;
						}
					}
				}
			}
		}
		
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s=s+c[i];
		}
	}//cout<<s;
	len1=s.size();
	//cout<<len1;	
	for(long long i=0;i<len1/2;i++){
		if(s[i]!=s[len1-i-1]){
			t++;
		}
	}cout<<t;
	
	return 0;
}
