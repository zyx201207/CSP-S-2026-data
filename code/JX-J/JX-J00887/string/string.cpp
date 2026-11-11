#include <bits/stdc++.h>
#define LL long long

using namespace std;

struct node{
	LL w;
	char c;
	node* nxt = NULL;
	node* lt = NULL;
};
void push_nxt(node* n,node* me){
	me->nxt = n->nxt;
	me->lt = n;
	if(n->nxt != NULL){
		n->nxt->lt = me;
	}
	n->nxt = me;
}
void push_lt(node* n,node* me){
	me->nxt = n;
	me->lt = n->lt;
	if(n->lt != NULL){
		n->lt->nxt = me;
	}
	n->lt = me;
}
void remo_nxt(node* n){
	if(n->nxt->nxt != NULL){
		n->nxt->nxt->lt = n;
	}
	n->nxt = n->nxt->nxt;
}
void remo_lt(node* n){
	if(n->lt->lt != NULL){
		n->lt->lt->nxt = n;
	}
	n->lt = n->lt->lt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	node* hd = NULL;
	node* tl = NULL;
	for(int i = 1;i <= n;i++){
		LL w;
		char c;
		cin >> w >> c;
		
		node* now = new node;
		now->w = w;
		now->c = c;
		if(hd == NULL){
			hd = now;
		}
		if(tl == NULL){
			tl = now;
		} else{
			push_nxt(tl,now);
			tl = now;
		}
	}
	
	for(node* i = hd;i != NULL;i = i->nxt){
		tl = i;
		while(true){
			node* me = i->nxt;
			if(me == NULL){
				break;
			}
			if(me->c != i->c){
				break;
			}
			i->w += me->w;
			remo_nxt(i);
		}
	}
	
	node* h = hd;
	node* t = tl;
	for(;h != NULL && t != NULL;h = h->nxt,t = t->lt){
		if(h->w > t->w){
			node* n = new node;
			n->w = (h->w)-(t->w);
			n->c = h->c;
			push_nxt(h,n);
			h->w = t->w;
		} else if(t->w > h->w){
			node* n = new node;
			n->w = (t->w)-(h->w);
			n->c = t->c;
			push_lt(t,n);
			t->w = h->w;
		}
	}
	
	h = hd,t = tl;
	LL ans = 0;
	for(;h != NULL && t != NULL;h = h->nxt,t = t->lt){
		if(h->c != t->c){
			ans += h->w;
			h->c = t->c;
		}
	}
	cout << ans;
	/*
	for(node* i = hd;i != NULL;i = i->nxt){
		cerr << i->w << " " << i->c << "\n";
	}
	*/
	return 0;
}
