#include<bits/stdc++.h>
using namespace std;
struct x{
	long long l=0;
	char c;
}s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,e=0,moa=0,mob=0;
	long long ans=0;
	char b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(i==0){
			s[0].l=a;
			s[0].c=b;
		}else{
			if(b==s[e].c)s[e].l+=a;
			else{
				e++;
				s[e].l=a;
				s[e].c=b;
			}
		}
	}for(int i=0;i<=e;i++){
		int pa=i+moa,pb=e-i+mob;
		x ta=s[pa],tb=s[pb];
		if(ta.l==tb.l){
			if(ta.c!=tb.c)ans+=ta.l;
		}else if(ta.l>tb.l){
			moa--;
			if(ta.c!=tb.c)ans+=tb.l;
			s[pa].l-=tb.l;
		}else{
			mob++;
			if(ta.c!=tb.c)ans+=ta.l;
			s[pb].l-=ta.l;
		}
	}cout<<ans;
}
