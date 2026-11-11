#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
};
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long l=1,r=n;
	node s[n+1];
	for(int i=1;i<=n;i++){
		long long b;char d;
		cin>>b>>d;
		s[i].a=b;
		s[i].c=d;
	}
	long long x=0;
	while(l<r){
		if(s[l].c!=s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				x+=s[r].a;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				x+=s[l].a;
				l++;
			}else{
				x+=s[l].a;
				l++;
				r--;
			}
		}else{
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
			}else{
				l++;
				r--;
			}
		}
		cout<<l<<" "<<r<<endl;
	}
	cout<<x;
	return 0;
}
