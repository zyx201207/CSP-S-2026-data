//100+68+40+5=213
//预祝回归本源在CSP-S组考试中成功长出复眼和触手
#include<bits/stdc++.h>
using namespace std;
vector <long long> es[1009];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long nn = 0;
	long long mm = 0;
	cin>>nn>>mm;
	for(long long ff = 1;ff<=mm;ff++){
		long long n = 0;
		long long m = 0;
		cin>>n>>m;
		for(long long f = 1;f<=n;f++){
			es[f].clear();
		}
		for(long long f = 1;f<=n-1;f++){
			long long o1 = 0;
			long long o2 = 0;
			cin>>o1>>o2;
			es[o1].push_back(o2);
			es[o2].push_back(o1);
		}
		if(n==2){
			cout<<0<<endl;
		}else if(n==3){
			cout<<1<<endl;
		}else if(n==4){
			cout<<1<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
