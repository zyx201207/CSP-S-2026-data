#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	ll num;
	char c;
}a[N];
deque<node> q;
int main(){
	freopen("string.in","r",stdin); //!!!
	freopen("string.out","w",stdout); //!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		q.push_back(a[i]);
		len++;
	}
	ll ans=0;
	while(len>1){
		node fr,ed;
		fr=q.front();
		ed=q.back();
		q.pop_front();
		q.pop_back();
		len-=2;
		if(fr.c!=ed.c){
			ans+=min(fr.num,ed.num);
		}
		if(fr.num>ed.num){
			q.push_front({fr.num-ed.num,fr.c});
			len++;
		}
		if(fr.num<ed.num){
			q.push_back({ed.num-fr.num,ed.c});
			len++;
		}
	}
	cout<<ans;
	return 0;
}