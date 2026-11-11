//AC+ 100 
#include<bits/stdc++.h>
#define fri(x,y) for(int i = x;i <= y;i++)
#define frj(x,y) for(int j = x;j <= y;j++)
#define MAXN 100000 + 10
#define lihaoming 0
#define ll long long
using namespace std;
struct duan{
	ll x;
	char c;
};
deque<duan> q;
int T;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		ll x;
		char y;
		cin>>x>>y;
		q.push_front((duan){x,y});
	}
	while(!q.empty()){
		duan x,y;//x=front,y=back
		x = q.front();
		y = q.back();
//		cout<<"size:"<<(int)q.size();
//		cout<<",front:{"<<x.x<<","<<x.c;
//		cout<<"},back:{"<<y.x<<","<<y.c<<"}"<<endl;
		if(x.c != y.c){
			ll qiu = min(x.x,y.x);
//			cout<<"ans:"<<ans<<"->";
			ans += qiu;
//			cout<<ans<<endl;
		}
		if((int)q.size() != 1) 
		q.pop_back();
		q.pop_front();
		if(x.x == y.x){}
		else if(x.x < y.x){
//			cout<<"push_back {"<<y.x - x.x<<","<<x.c<<"}\n";
			q.push_back((duan){y.x - x.x,y.c});
		}
		else{
//			cout<<"push_front{"<<x.x - y.x<<","<<x.c<<"}\n";
			q.push_front((duan){x.x - y.x,x.c});
		}
	}
	cout<<ans;
	return lihaoming;
}
/*
text
10 1 a 2 b 3 c 4 d 5 e 6 f 7 g 8 h 9 i 10 j

out:27
*/
