#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool f;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=n;i>=1;i--){
		int k=0;
		f=0;
		for(int j=1;j<i;j++){
			k=k+a[i]-a[j];
			if(k>m){
				f=1;
				break;
			}
		}
		if(!f){
			cout<<i;
			break;
		}
	}
	if(f){
		cout<<1;
	}

	return 0;
}
//Trick||Treat!
//Oct31==Dec25?
/*
luogu uid=1087601如果有人看到的话请关注我谢谢 
打眼一看怎么全是图论
又看一眼发现很奇怪
感觉只有T1的30pts可以拿了
炸... 
*/ 
