#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct str{
	long long m;
	char c;
}g[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	long long sum=0,h=0;
	for(int i=1;i<=n;i++){
		cin>>g[i].m>>g[i].c;
		h+=g[i].m;
		//cout<<g[i].m<<g[i].c;
	}
	int p=1,q=n;//p mean front now,q mean last now;
	long long cnt=0;
	while(cnt<=h/2){
		//cout<<h;
		if(g[p].m==0)p++;
		if(g[q].m==0)q--;
		if(g[p].c==g[q].c){
			//if(g[p].m==0)p++;
			//if(g[q].m==0)q--;
			cnt+=min(g[p].m,g[q].m);
			g[p].m-=min(g[p].m,g[q].m);
			g[q].m-=min(g[p].m,g[q].m);
		}
		else {
			//if(g[p].m==0)p++;
			//if(g[q].m==0)q--;
			//g[p].m-=min(g[p].m,g[q].m);
			//g[q].m-=min(g[p].m,g[q].m);
			cnt+=min(g[p].m,g[q].m);
			sum+=min(g[p].m,g[q].m);
			g[p].m-=min(g[p].m,g[q].m);
			g[q].m-=min(g[p].m,g[q].m);
		}
		//cout<<g[p].m<<" "<<g[q].m<<" "<<g[p].c<<g[q].c<<" ";
	}
	cout<<sum;
	return 0;
}