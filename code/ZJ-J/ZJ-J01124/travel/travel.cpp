#include <bits/stdc++.h>
#define int long long
using namespace std;
char a[10],b[10],c[10],d[10];
map<char,int> f;
int ans1,ans2,i;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a+1>>b+1>>c+1>>d+1;
	if(a[1]==c[1]&&a[2]==c[2]) cout<<1;
	else{
		for(i=1;i<=4;i++) cout<<0;
		return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		cout<<1;
		f[b[3]]++;
		f[d[3]]++;
		ans1=f['D']+f['F'];
		ans2=f['A']+f['B']+f['C'];
		if(ans1==2){
			cout<<11;
		}
		else if(ans2==2){
			cout<<1;
			if(f['A']&&f['B']||f['B']&&f['C']) cout<<1;
			else cout<<0;
		}
		else{
			for(i=1;i<=2;i++) cout<<0;
			return 0;
		}
	}
	else{
		for(i=1;i<=3;i++) cout<<0;
	}
	return 0;
}