#include<bits/stdc++.h>
using namespace std;
long long n,s[200010],ans,H,E,cnt;
long long a;
char c,p[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		p[i]=c;
		s[i]=a;
	}
	H=1,E=n;
	while(H!=E){
		cnt=min(s[H],s[E]);
		s[H]-=cnt;
		s[E]-=cnt;
		if(p[H]!=p[E]){
			ans+=cnt;
		}
		if(!s[H]){
			H++;	
		}else{
			E--;	
		}
	}
	cout<<ans;
	return 0;
}
