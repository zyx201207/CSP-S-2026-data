#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s,m;
char a[500001];
int b[500001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		m+=b[i];
	}
	int i=1,j=n,l=b[1],r=b[n];
	while(i<j){
		if(a[i]!=a[j]){
			s+=min(l,r);
		}
		int x=l,y=r;
		l=l-min(x,y);
		r=r-min(x,y);
		if(l<=0){
			i++;
			l=b[i];
		}
		if(r<=0){
			j--;
			r=b[j];
		}
	}
	cout<<s<<endl;
	return 0;
}
//Trick||Treat!

