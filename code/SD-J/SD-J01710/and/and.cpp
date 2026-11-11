#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read(){
	int x=0,f=1;char ch=getchar();
	if(ch=='-'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;

int ans;

void f(vector<int> a,int deg){
	if(deg<0) return;
	vector<int> d[40];
	for(int i=0;i<a.size();i++){
		for(int j=0;j<=30;j++){
			int p=pow(2,j);
			if(a[i]&p) d[j].push_back(i);
		}
	}
	vector<int> aa;
	for(int i=deg-1;i>=0;i--){
		if(d[i].size()>=m){
			ans+=pow(2,i);
			for(int j=0;j<d[i].size();j++) aa.push_back(a[d[i][j]]);
			f(aa,i);
			break;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	vector<int> a;
	for(int i=1;i<=n;i++) a.push_back(read());
	f(a,40);
	cout<<ans;
	return 0;
}

