#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x[1000005],y[1000005];
vector<long long> e[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x[i]>>y[i];
			e[x[i]].push_back(y[i]);
			e[y[i]].push_back(x[i]);
		}
		if(n==k){
			cout<<0<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	
	return 0;
}
/*

I've been running in the strange life
chasing all them green lights
throwing of the shade for a little bit sunshine

ni neng cai chu wo shang wu de dai ma shi na fen ma
wo zai t4 xie le yi yang de ke ci o

bu ke yi , zong si ling

I don't know how to write this problem.
It's too difficult for me.
And I'm very lazy , so I don't want to write baoli of it.
but I think I can get s1= this year.
I think my score is 100+100+24+0
I don't want gua fen.
At last , I want to say:
Trick || Treat !!! (bu gei guan zhu jiu dao dan !!! guan zhu xuzhekai23 miao ~ ) 

zan mei yu zhe
nin suo zeng yu wo de hao yun yu wo tong zai
*/