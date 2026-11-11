#include<bits/stdc++.h>
using namespace std;

const int N=20010;
int n,a[N];
char q[N],ans[N],c[N];
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//cin>>n;
	for(int i=1;i<=n;++i){
		int a;
		char c;
//		a[i]=a;
//		q[i]=c;
	}
	for(int i=1;i<=n;++i){	
		for(int j=1;j<=a[i];++j){
			ans[j]=q[i];
			c[j]=q[i];
		}
	}
	for(int i=c.size()-1,j=0;i>0,j<ans.size();--i,++j){
		c[i]=ans[j];
	}
	for(int i=0;i<=ans.size();++i){
		if(ans[i]!=c[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}