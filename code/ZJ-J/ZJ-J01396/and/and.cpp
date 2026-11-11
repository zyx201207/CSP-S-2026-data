#include<bits/stdc++.h>
using namespace std;
bitset<31>a[200001],c;
bitset<200001>b,d;
int n,m,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m,b.set();
	for(int i=1;i<=n;i++){
		int x;
		cin>>x,a[i]=x;
	}
	for(int i=30;i>=0;i--){
		s=0,d=b;
		for(int j=1;j<=n;j++){
			if(a[j][i]&&b[j])s++;
			else b[j]=0;
		} 
		if(s<m)b=d;
		else c[i]=1;
	}
	cout<<c.to_ulong();
	return 0;
}
