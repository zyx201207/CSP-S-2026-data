#include<bits/stdc++.h>
using namespace std;
int n,m,new_pos;
struct node{
	int l=-1,r=-1,num;
}trie[4304000];
void insert(int num){
	int w=0;
	for(int i=30;i>=1;i--){
		if(!((1<<i)&num)){
			if(trie[w].l==-1)trie[w].l=++new_pos;
			w=trie[w].l;
		}
		else{
			if(trie[w].r==-1)trie[w].r=++new_pos;
			w=trie[w].r;
		}
		trie[w].num++;
	}
}
int find(){
	int w=0,ans=0;
	for(int i=31;i>=1;i--){
		ans<<=1;
		if(trie[w].r!=-1&&trie[trie[w].r].num>=m){
			w=trie[w].r;
			ans++;
		}
		else if(trie[w].l!=-1&&trie[trie[w].l].num>=m)w=trie[w].l;
		else{
			ans<<=(i-1);
			break;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		insert(x);
	}
	cout<<find();
	return 0;
}