#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<node>s(n+1);
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	long long cnt=0,l=1,r=n;
	while(l<=r){
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a){
				l++;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
			}else if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
		}else{
			cnt+=min(s[l].a,s[r].a);
			if(s[l].a==s[r].a){
				l++;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
			}else if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}