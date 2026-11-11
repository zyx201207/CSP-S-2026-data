#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Tnode{
	ll num;
	vector<Tnode*> tos;
	ll deep=-1;
};
bool cmp(Tnode* a,Tnode* b){return a->deep > b->deep;}
vector<Tnode*> pts;
vector<Tnode*> leaves;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	short c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		for(int i=0;i<n;i++){
			pts.push_back(new Tnode);pts[i]->num=i;
		}
		for(int i=0;i<n-1;i++){
			ll a,b;cin>>a>>b;
			pts[a-1]->tos.push_back(pts[b-1]);
			pts[b-1]->tos.push_back(pts[a-1]);
		}
		
		pts[0]->deep=0;
		queue<Tnode*> transing;
		transing.push(pts[0]);
		while(transing.size()){
			vector<Tnode*> now=transing.front()->tos;ll nowdeep=transing.front()->deep;
			for(int i=0;i<now.size();i++) if(now[i]->deep==-1){
				transing.push(now[i]);
				now[i]->deep=nowdeep+1;
			}
			transing.pop();
		}
		
		for(int i=0;i<pts[0]->tos.size();i++){
			bool vis[n+5]={};Tnode* ans=NULL;
			transing.push(pts[0]->tos[i]);
			while(transing.size()){
				bool isL=1;
				vector<Tnode*> now=transing.front()->tos;ll nowdeep=transing.front()->deep;
				for(int i=0;i<now.size();i++) if(!vis[now[i]->num]){
					transing.push(now[i]);
					isL=0;
				}
				if(isL){
					if(ans==NULL) ans=transing.front();
					else if(ans->deep<nowdeep) ans=transing.front();
				}
				transing.pop();
			}
			leaves.push_back(ans);
		}sort(leaves.begin(),leaves.end(),cmp);
		ll mxl=leaves.size()>2?leaves[2]->deep:0,ans=1e10;
		while(leaves.size()>2) leaves.pop_back();
		ll i=0;
		for(;i<n;i++){
			Tnode *a1=leaves[0],*a2=leaves[1];
			for(ll j=0;j<k;j++){
				if(a1->deep>a2->deep){
					Tnode *t=a1;a1=a2;a2=t;
				}
				for(ll j=0;j<a1->tos.size();j++) if(a1->tos[j]->deep<a1->deep){
					a1=a1->tos[j];break;
				}
			}
			if(mxl==0){
				if(min(a1->deep,a2->deep)<=i) break;
			}else{
				if(min(a1->deep,a2->deep)+mxl<=i) break;
			}
			for(ll j=0;j<leaves[0]->tos.size();j++) if(leaves[0]->tos[j]->deep<leaves[0]->deep){
				leaves[0]=leaves[0]->tos[j];break;
			}for(ll j=0;j<leaves[1]->tos.size();j++) if(leaves[1]->tos[j]->deep<leaves[1]->deep){
				leaves[1]=leaves[1]->tos[j];break;
			}
		}
		cout<<i<<'\n';
		pts.clear();leaves.clear();
	}
	return 0;
}

