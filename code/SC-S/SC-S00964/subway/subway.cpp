// 2.subway
// N
#include<bits/stdc++.h>
using namespace std;

void read(int &n){
	n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		n=n*10+int(ch-'0');
		ch=getchar();
	}
}

int c,n,m,d,q;
vector<int> w,x,y;
vector<vector<int>> a,t;

int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	w.resize(m+2);a.resize(n);
	for(int i=1;i<=m;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;read(k);
		for(int j=1;j<=1+2*k;j++){
			int at,tt;read(at);read(tt);
			a[i].push_back(at);t[i].push_back(tt);
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;read(x);read(y);
		
	}
	return 0;
}
