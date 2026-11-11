#include<bits/stdc++.h>
using namespace std;
#define _ long long
#define h_nxt_______1 jabjsbfjbdjcbjjdjnxnsau//shi luan da de, wu shiji yiyi.
_ a,b,c,d,e,f[500001],g,h,h_nxt_______1,ans[500001],how_old_the_ans[500001],how_old_the_line_is_ok[501],at_to_station[501];
vector<pair<_,_>>what_have_the_line[501];
vector<pair<_,_>>what_have_the_station[500001];
struct Node{
	_ x,y;
	bool operator<(const Node&oth)const{
		return x>oth.x;
	}
};
priority_queue<Node>q;
queue<Node>q2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d>>e;
	for(_ i=1;i<=c;i++){
		cin>>f[i];
	}
	for(_ i=1;i<=b;i++){
		cin>>g;
		for(_ j=1;j<=g;j++){
			cin>>h>>h_nxt_______1;
			what_have_the_line[i].push_back({h,h_nxt_______1});
			what_have_the_station[h].push_back({i,h_nxt_______1});
		}
	}
	if(12<=a&&a<=19){
		for(_ i=1;i<=e;i++){
			cin>>g>>h;
			q2.push({f[g]+f[h],g});
			while(!q2.empty()){
				auto f=q2.front();
	//			cerr<<f.x<<' '<<f.y<<'\n';
				q2.pop();
				if(f.y==h){
					cout<<f.x<<'\n';
					while(!q2.empty())q2.pop();
					break;
				}
				if(how_old_the_ans[f.y]<i){
					how_old_the_ans[f.y]=i;
				}
				else continue;
				for(auto j:what_have_the_station[f.y]){
					if(how_old_the_line_is_ok[j.first]<i){
						how_old_the_line_is_ok[j.first]=i;
						for(auto k:what_have_the_line[j.first]){
							if(how_old_the_ans[k.first]<i){
								q2.push({f.x+j.second+k.second,k.first});
							}
						}
					}
				}
			}
		}
		return 0;
	}
	for(_ i=1;i<=e;i++){
		cin>>g>>h;
		q.push({f[g]+f[h],g});
		while(!q.empty()){
			auto f=q.top();
//			cerr<<f.x<<' '<<f.y<<'\n';
			q.pop();
			if(f.y==h){
				cout<<f.x<<'\n';
				while(!q.empty())q.pop();
				break;
			}
			if(how_old_the_ans[f.y]<i){
				how_old_the_ans[f.y]=i;
				ans[f.y]=f.x;
			}
			else continue;
			for(auto j:what_have_the_station[f.y]){
				if(how_old_the_line_is_ok[j.first]<i||at_to_station[j.first]>f.x+j.second){
					how_old_the_line_is_ok[j.first]=i;
					at_to_station[j.first]=f.x+j.second;
					for(auto k:what_have_the_line[j.first]){
						if(how_old_the_ans[k.first]<i){
							q.push({f.x+j.second+k.second,k.first});
						}
					}
				}
			}
		}
//		cerr<<'\n';
	}
	return 0;
}