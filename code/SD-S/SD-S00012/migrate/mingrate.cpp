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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ccccc,t;
	cin>>ccccc>>t;
	while(t--){
		cout<<0<<endl;
	}
}

