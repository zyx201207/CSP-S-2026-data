//T1
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct node{
	int c,s;
	char b;
}a,b;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a.c,&a.s,&a.b,&b.c,&b.s,&b.b);
	cout<<(a.c==b.c);
	cout<<((a.c==b.c)&&(a.s==b.s));
	cout<<(((a.b<'D'&&b.b<'D')||(a.b>'C'&&b.b>'C'))&&((a.c==b.c)&&(a.s==b.s)));
	cout<<(((a.c==b.c)&&(a.s==b.s)&&((a.b<'D'&&b.b<'D')||(a.b>'C'&&b.b>'C')))&&(abs(a.b-b.b)==1));
	return 0;
}
