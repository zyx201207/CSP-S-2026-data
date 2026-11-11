#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long a;
	char b;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out" ,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	ans=0;
	long long l=1,r=n;
	while(l<r){
		if(s[l].b==s[r].b){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
			}else{
				l++,r--;
			}
		}else if(s[l].a>=s[r].a){
			ans+=s[r].a;
			s[l].a-=s[r].a;
			r--;
		}else{
			ans+=s[l].a;
			s[r].a-=s[l].a;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
