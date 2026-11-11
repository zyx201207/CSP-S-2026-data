#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5;
int n,m;
int num[N];
vector<int>t;
int ans[N];

void push(int card){
	int tmp=-1;
	for(int i=0;i<t.size();i++){
		if(t[i]==card){
			tmp=i;
			break;
		}
	}
	if(tmp==-1)t.push_back(card);
	else{
		t.erase(t.begin()+tmp,t.end());
		t.push_back(card);
	}
}

void count(){
	for(auto i:t){
		ans[i]++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int round=1;round<=n;round++){
		t.clear();
		for(int card=round;card<=n;card++){
			push(num[card]);
		}
		count();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
