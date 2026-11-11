#include<bits/stdc++.h>
#define int long long
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n,m;
int a[200100];
int b[200100][40];
int c[40];
vector<int> d;
vector<int> e;
int s[40];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		d.push_back(i);
		int x=a[i];
		for(int j=1;x>=1;j++){
			if(x%2==1){
				b[i][j]=1;
				c[j]++;
			} 
			x/=2;
		}
	} 
	int t=35;
	while(c[t]<m&&t>=1){
		t--;
	}
	for(int i=t;i>=1;i--){
		e.clear();
		int q=0;
		for(int j=0;j<=d.size()-1;j++){
			if(b[d[j]][i]==1){
				q++;
				e.push_back(d[j]);
			}
		}
		if(q>=m){
			d.clear();
			for(int j=0;j<=e.size()-1;j++){
				d.push_back(e[j]);
			}
			s[i]=1;
		}
	}
	int w=1;
	long long s1=0;
	for(int i=1;i<=31;i++){
		if(s[i]==1) s1+=w;
		w*=2;
	}
	cout<<s1;
	return 0;
}
