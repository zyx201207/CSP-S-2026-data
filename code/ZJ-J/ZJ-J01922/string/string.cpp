#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+5;
int n;
long long ans;
struct node{
	int a;
	char c;
}m[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>m[i].a>>m[i].c;
	int i=1,j=n;
	while(i>=1&&i<=n&&j>=1&&j<=n&&i<j){
		int mmin=min(m[i].a,m[j].a);
//		cout<<i<<":"<<m[i].a<<" "<<m[i].c<<" // "<<j<<":"<<m[j].a<<" "<<m[j].c<<" mmin:"<<mmin<<endl;
		if(m[i].c!=m[j].c) ans+=mmin;
		m[i].a-=mmin;
		m[j].a-=mmin;
		if(m[i].a==0) i++;
		if(m[j].a==0) j--;
	}
	cout<<ans<<endl;
	return 0;
}

