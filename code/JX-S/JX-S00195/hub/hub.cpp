#include<bits/stdc++.h>

#define ll long long
#define ris(x,y,z) for(ll x=y;x<z+1;++x)
#define ful(x,y,z) for(ll x=y;x>z-1;--x)
#define riso(x,y,z,a) for(ll x=y;x!=a;x=z)
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

using namespace std;

const ll N=1e6+5;

ll c,t,n,k;

struct gragh{
	struct edge{
		ll t,n;
	}e[N<<1];
	
	ll h[N],cnt=0;
	
	void add(ll u,ll v){
		e[++cnt]={v,h[u]};
		h[u]=cnt;
	}
}d;

signed main(){
	fre("hub");
	ios::sync_with_stdio(0);
	cin.tie(0),
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		d.cnt=0;
		if(k==n){
			cout<<"0\n";
			continue;
		}
		ris(i,1,n-1){
			ll u,v;
			cin>>u>>v;
			d.add(u,v);
			d.add(v,u);
		}
		if(c==0||c==13||c==14){
			ll m=n/2;
			if(k>=m){
				cout<<"1\n";
				continue;
			}
			ll d=m-k;
			d*=2;
			++d;
			d=d/2-1;
			cout<<d<<'\n';
			continue;
		}
	}
	return 0;
} 
/*
//NothingtoSay

#include<bits/stdc++.h>

#define ll long long

struct sw{
	ll minatk,maxatk;
};

struct people{
	ll hp,minatk,maxatk;
	std::string name;
	sw hand;
};

signed main(){
	return 0;
	std::cout<<"It was a terrible day...\n";
	std::cout<<"And you will be in an terrible adventure...\n";
	std::cout<<"Are you ready?\n";

	people You;
	You.hp=50;
	You.minatk=0;
	You.maxatk=0;

	std::cout<<"Town Violet\n";
	std::cout<<"Hunter:Helle,guy.What's your name?\n";
	std::cin>>You.name;
	
	bettle1;
	std::cout<<"Hunter:Oh,good day,"<<You.name<<".You are new in town,let me tell something to you...\n";

	std::cout<<"Bettle layer\n";
	std::cout<<"Hunter:In Violet,we are fond to bettle--it's really a good way to relax.\n";
	std::cout<<"Hunter:Hold it!\n";
	std::cout<<"You get stick.\n";

	sw Stick;
	Stick.minatk=1;
	Stick.maxatk=5;
	You.hand=Stick;

	std::cout<<"MinAtk"<<You.minatk<<"->"<<You.minatk+You.hand.minatk<<'\n';
	std::cout<<"MaxAtk"<<You.maxatk<<"->"<<You.maxatk+You.hand.maxatk<<'\n';

	people Hunter;
	Hunter.hp=20;
	Hunter.minatk=0;
	Hunter.maxatk=0;
	Hunter.hand=Stick;
	while(Hunter.hp>0&&You.hp>0){
		ll yatk=rand()%5+1,hatk=rand()%5+1;
		std::cout<<"Hunter:You can ateack.\n1.Atk\n2.Def\n\n";
		char x;
		std::cin>>x;
		if(x=='1'){
			Hunter.hp-=yatk;
			You.hp-=hatk;
			std::cout<<"Hunter"<<std::max(0LL,Hunter.hp)<<'\n';
			std::cout<<"You"<<std::max(0LL,You.hp)<<'\n';
		}
		else{
			ll d=hatk-yatk;
			if(d>=0)
				You.hp-=d;
			else
				Hunter.hp+=d;
			std::cout<<"Hunter"<<std::max(0LL,Hunter.hp)<<'\n';
			std::cout<<"You"<<std::max(0LL,You.hp)<<'\n';
		}
	}
	if(You.hp<=0)
		goto bettle1;
	else
		std::cout<<"You win.\n";
}
 
*/
