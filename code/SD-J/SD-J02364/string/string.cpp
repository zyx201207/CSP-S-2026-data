#include<bits/stdc++.h>
using namespace std;
struct date{
	long long a;
	char c;
}s[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(s[l].c!=s[r].c){
			if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
			else{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
		}
		else{
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}
			else{
				s[r].a-=s[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
