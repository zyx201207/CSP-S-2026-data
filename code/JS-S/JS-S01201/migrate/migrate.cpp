#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define elif else if

int c,t,n;
ll d,x[2000001];
struct node{
	int n,s;
};

bool equal(node& a,node& b){
	return a.n==b.n&&a.s==b.s;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n-1;i++){
			int j;
			for(j=i+1;j<n&&x[j]-x[i]<=d;j++);
			x[i]=j-1;
		}
		x[n-1]=0;
		node k;
		vector<node> qu;
		int l=0;
		k.n=k.s=0;
		qu.push_back(k);
		while((int)qu.size()>l){
			//cout<<l<<' ';
			k=qu[l];
			node m=k;
			m.s++;
			for(int i=k.n+1;i<=x[k.n];i++){
				m.n=i;
				qu.push_back(m);
			}
			while(equal(k,qu[l])) l++;
		}
		int res=0;
		for(size_t i=0;i<qu.size()-1;i++){
			if(equal(qu[i],qu[i+1])&&(!equal(qu[i],qu[i+2]))) res++;
		}
		cout<<res<<'\n';
	}
	return 0;
}
