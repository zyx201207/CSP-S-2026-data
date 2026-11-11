#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char c;
};
long long n;
st s[100005];
long long l,r,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		cout<<s[i].a<<" "<<s[i].c<<endl;
	}
	l=1,r=n;
	while(r>l){
		if(s[l].a>s[r].a){
			if(s[l].c!=s[r].c){
				cnt+=s[r].a;
			}
			s[l].a-=s[r].a;
			s[r].a=0;
			r--;
			cout<<cnt<<"#1"<<endl;
		}else if(s[l].a<s[r].a){
			if(s[l].c!=s[r].c){
				cnt+=s[l].a;
			}
			s[r].a-=s[l].a;
			s[l].a=0;
			l++;
			cout<<cnt<<"#2"<<endl;
		}else if(s[l].a==s[r].a){
			if(s[l].c!=s[r].c){
				cnt+=s[r].a;
			}
			s[r].a=s[l].a=0;
			r--;
			l++;
			cout<<cnt<<"#3"<<endl;
		}
	}
	cout<<cnt;
	return 0;
} 
