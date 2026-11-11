#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define xx first
#define yy second
const int N=5e5+10;
int a[N];
int b[N];
int st[N];
int main(){
	freopen("card3.in","r",stdin);
	freopen("card33.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool oka=1,okb=1; 
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		if(a[i]<a[i-1]) oka=0;
		if(a[i]==a[i-1]) okb=0;
	}
	//A
	if(oka){
		for(int i=1;i<=n;++i){
			if(a[i+1]>a[i]) b[a[i]]=i;
		}
		b[m]=n;
		for(int i=1;i<=m;++i) cout<<b[i]<<" ";
		cout<<endl;
		return 0;
	}
	//o(n^2)
	for(int d=1;d<=n;++d){//µÚ¼¸¾Ö 
		memset(st,0,sizeof st);
		stack<int> s;
		for(int i=d;i<=n;++i){//a[i]
			if(!st[a[i]])s.push(a[i]),st[a[i]]=1;
			else{
				while(!s.empty()){
					if(s.top()==a[i]) break;
					st[s.top()]=0;
					s.pop();
				}
				if(!s.empty()&&s.top()==a[i]) st[s.top()]=0,s.pop();
				s.push(a[i]);
				st[a[i]]=1;
			}
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;++i) cout<<b[i]<<" "; 
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/
//3 1 
/*
4 3
1 2 1 3
*/
