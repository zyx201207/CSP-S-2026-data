#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Node{
	int rnd,val;
	int ls,rs;
	int siz;
}tr[N];
int rt,tot;
void pushup(int x){
	tr[x].siz=tr[tr[x].ls].siz+tr[tr[x].rs].siz+1;
}
void split(int&ls,int&rs,int x,int y){
	if(tr[x].val<=y){
		ls=x;
		split(tr[x].rs,rs,tr[x].rs,y);
	}else{
		rs=x;
		split(ls,tr[x].ls,tr[x].ls,y);
	}
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(tr[x].val>tr[y].val)swap(x,y);
	if(tr[x].rnd>tr[y].rnd){
		tr[x].rs=merge(tr[x].rs,y);
		pushup(x);
		return x;
	}else{
		tr[y].ls=merge(x,tr[y].ls);
		pushup(y);
		return y;
	}
}
int newNode(int x){
	tr[++tot]={rand(),x,0,0,1};
	return tot;
}
void insert(int x){
	if(!rt){
		rt=newNode(x);
	}else{
		rt=merge(rt,newNode(x));
	}
}
void Delete(int x){
	int A,B;
	split(rt,A,rt,x);
	split(rt,B,rt,x-1);
	B=merge(tr[B].ls,tr[B].rs);
	rt=merge(rt,merge(B,A));
}
int rks(int k){
	int A;
	split(rt,A,rt,k-1);
	int ans=tr[rt].siz+1;
	rt=merge(rt,A);
	return ans;
}
int kth(int t,int k){
	int p=tr[tr[t].ls].siz+1;
	if(p==k)return tr[t].val;
	if(p>k){
		return kth(tr[t].ls,k);
	}
	return kth(tr[t].rs,k-p);
}
int kth(int k){
	return kth(rt,k);
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	srand(time(0));
	return 0;
}