#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010];
long long read(){
	long long s=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=i;j<=n;j++){
			int k=-1;
			for(int l=0;1ull*l<v.size();l++)if(v[l]==a[j]){k=l;break;}
			if(k!=-1)while(1ull*k<v.size()){b[v.back()]--;v.pop_back();}
			v.push_back(a[j]);
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
