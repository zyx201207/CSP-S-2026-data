#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0;
struct stru{
	int a,c;
	long long x,y;
}s[200001];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		s[i].x=l+1;
		cin>>s[i].a;
		l+=s[i].a;
		s[i].y=l;
		char lt;
		cin>>lt;
		s[i].c=lt-'a'+1;
	}
	int p=1,q=n;
	while(p<=q){
		bool tc=(s[p].c!=s[q].c?1:0);
		if(s[p].y+s[q].x>l+1){
			if(tc) ans+=s[q].y-s[q].x+1;
			s[p].x+=s[q].y-s[q].x+1;
			q--;
			continue;
		}else if(s[p].y+s[q].x<l+1){
			if(tc) ans+=s[p].y-s[p].x+1;
			s[q].y-=s[p].y-s[p].x+1;
			p++;
			continue;
		}else{
			if(tc) ans+=s[q].y-s[q].x+1;
			p++;q--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

