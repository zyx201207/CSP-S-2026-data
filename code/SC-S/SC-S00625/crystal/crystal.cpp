#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool ufl=1,ufl2=1,ufl3=1;
	cin>>a[1];if(a[1]!=1)ufl=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)ufl=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])ufl2=0;
		if(i>=3)
			if(a[i-1]-a[i-2]!=a[i]-a[i-1])ufl3=0;
	}
	if(ufl){
		int fl;
		for(fl=2;m-fl+1>=0;fl++)m-=fl-1;
		cout<<fl-1<<endl;
		return 0;
	}else if(ufl2||ufl3){
		int fl,cha=abs(a[2]-a[1]);
		for(fl=2;m-(fl-1)*cha+1>=0;fl++)m=m-(fl-1)*cha;
		cout<<fl-1<<endl;
		return 0;
	}
	return 0;
}