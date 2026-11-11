#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N = 2e5+5;
int n;
struct node{
	int next;
	int last;
	long long x;
	char s;
}stu[N];
void del(int l,int r){
	stu[l].next=stu[r].next;
	stu[stu[r].next].last=l;
	stu[r].x=0;
	stu[r].s=' ';
}
void merge(int l,int r){
	stu[l].x+=stu[r].x;
	del(l,r);
}
void minuss(int it,long long diff){
	stu[it].x-=diff;
	if(stu[it].x==0) del(stu[it].last,it); 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	zhr;
	cin>>n;
	for(int i=1;i<=n;i++){
		stu[i].next=i+1;
		stu[i].last=i-1;
		cin>>stu[i].x>>stu[i].s;
	}
	int l=1,r=1;
	for(int i=2;i<=n;i++){
		int it = stu[i].last;
		if(stu[it].s == stu[i].s) {
			merge(it,i);
		}
		else r=i;
	}
	long long ans=0;
	while(l<r){
		
		int it = stu[l].next;
		long long diff = min(stu[l].x,stu[r].x);
		if(stu[l].s!=stu[r].s){
			ans+=diff;
		}
		minuss(l,diff);
		minuss(r,diff);
		if(stu[l].x==0) l=stu[l].next;
		if(stu[r].x==0) r=stu[r].last;
	}
	cout<<ans;
	return 0;
}

