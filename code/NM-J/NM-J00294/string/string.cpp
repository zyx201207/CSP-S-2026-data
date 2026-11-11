#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct hw{
	int a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	string ss;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
		ss+=s[i].c;
	}
	long long l=0,r=ss.size()-1;
	while(l<r){
		if(ss.size()==1) break;
		if(ss[l]!=ss[r]){
			cnt+=min(s[l].a,s[r].a);
			if(s[l].a<s[r].a){
				ss=ss.substr(1);
				s[r].a-=s[l].a;
			}
			else if(s[l].a>s[r].a){
				ss=ss.substr(0,ss.size()-1);
				s[l].a-=s[r].a;
				r=ss.size()-1;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<cnt;
    return 0;
}
