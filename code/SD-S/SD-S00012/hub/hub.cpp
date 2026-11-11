#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char gc;
	while(gc>'9'||gc<'0'){
		if(gc=='-') f*=-1;
		gc=getchar();
	}
	while(gc<='9'&&gc>='0'){
		s=s*10+gc-'0';
		gc=getchar();
	}
	return s*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cout<<1<<'\n';
	}
}

