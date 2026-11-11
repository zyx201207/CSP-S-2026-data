#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans=0;
struct lt{
	long long l,r;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[0].l=s[0].r=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>s[i].c;
		s[i].l=s[i-1].r+1;
		s[i].r=s[i].l+a-1;
	}
	long long len=s[n].r;
	int i=1,j=n;
	while(i<j){
		int dr=len-s[i].r+1;
		if(s[j].l>dr){
			int m=s[j].r-s[j].l+1;
			if(s[j].c!=s[i].c)ans+=m;
			s[i].l+=m; 
			j--;
		}
		else if(s[j].l<dr){
			int m=s[i].r-s[i].l+1;
			if(s[j].c!=s[i].c)ans+=m;
			s[j].r-=m;
			i++;
		}
		else{
			i++;
			j--;
			if(s[j].c!=s[i].c)ans+=s[i].r-s[i].l+1;
		}
	}
	cout<<ans;
	return 0;
}