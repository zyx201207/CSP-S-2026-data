#include<bits/stdc++.h>
using namespace std;
string s;
int ccc[1000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n=0,ans=0,syg=-1,num=0;
	cin>>c;
	if(c==1){
		cout<<0;
		return 0;
	}
	while(c--){
		int a;
		char b;
		cin>>a>>b;
		int zz=(int)b;
		if(ccc[zz]==0)num++;
		ans+=a-ccc[zz];
		ccc[zz]-=a;
		if(syg==zz)ccc[zz]+=a*2;
		if(ccc[zz]<0)ccc[zz]*=-1;
		syg=zz;
		//while(a--)s[n++]=b;
	}
	if(num==1)cout<<0;
	else cout<<ans/2;
	return 0;
}
