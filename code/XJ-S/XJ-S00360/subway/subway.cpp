#include<bits/stdc++.h>
using namespace std;
const long long P=5e5+5;
struct su{
	long long time,stop;
}sub[P];
struct pl{
	long long st,en;
}plan[P];
long long stop[P]
int main(){

	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>stop[i];
	while(m--){
		int N;
		cin>>N;
		for(int i=1;i<=N;i++)cin>>sub[i].stop>>sub[i].time ;
	}
	int t=1;
	while(t<=q){
		cin>>plan[t].st>>plan[t].en;
		
	}
	
	return 0;
} 
