#include<bits/stdc++.h>
using namespace std;
struct xb{
	int shuliang;
	char zifu;
};
int main(){
	int a,zong,y=0;
	string f[]={};
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>xb.shuliang;
		cin>>xb.zifu;
		zong=zong+xb.shuliang;
		for(int j=0;j<xb.shuliang;j++){
			f[y]=xb.zifu;
			y++;
		}
	}
	cout<<zong;
	return 0;
}
