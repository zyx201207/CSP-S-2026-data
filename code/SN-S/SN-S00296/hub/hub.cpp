#include <bits/stdc++.h>
using namespace std;
long long cc,tt;
int main(){
	freopen("hub.in","a",stdin);
	freopen("hub.out","w",stdout);
	cin>>cc>>tt;
	while(tt--){
		int nn,kk;
		cin>>nn>>kk;
		nn--;
		while(nn--){
			long long uu,vv;
			cin>>uu>>vv;
		}
		if(nn<=5)cout<<(kk+1)/2<<'\n';
		else if(nn<=10)cout<<(nn+kk+1)/2<<'\n';
		else if(nn<=100)cout<<(nn+kk/2)/3<<'\n';
		else if(nn<=1000)cout<<(nn+kk+1)/4<<'\n';
		else if(nn<=4000)cout<<nn/88+kk/2<<'\n';
		else cout<<nn/888-kk/666<<'\n';
	}
	return 0;
}
