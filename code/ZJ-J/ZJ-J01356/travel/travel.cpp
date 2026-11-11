#include<bits/stdc++.h>
using namespace std;
//using LL=long long;
//#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
string a[3],b[3];
bool f[5];
void solve(){
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	a[2]=a[1][0]+a[1][1];
	b[2]=b[1][0]+b[1][1];
	if(a[0]==b[0]){
		f[0]=1;
		if(a[2]==b[2]){
			f[1]=1;
			char i=a[1][2];
			char j=b[1][2];
			if(i>j)swap(i,j);
			if(('A'<=i && j<='C') || (i=='D' && j=='F')){
				f[2]=1;
				if(j-i==1)f[3]=1;
			}
		}
	}
	cout<<f[0]<<f[1]<<f[2]<<f[3];
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
