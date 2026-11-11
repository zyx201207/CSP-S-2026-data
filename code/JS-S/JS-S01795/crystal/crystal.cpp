#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int n,mx=-1,s=1;
long long m;
void crystal(int x){
	int f;
	if(m<c[x]||x==s||b[x]==0)return;
	b[x]--;
	b[x+1]++;
	mx=max(mx,b[x+1]);
	m-=c[x];
	if(b[x]==0) f=x+1,crystal(x+1);
	else f=x,crystal(x);
	m+=c[x];b[x]++;b[x+1]--;
	crystal(f+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	memset(b,0,sizeof b);
	b[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			s++;
			c[s-1]=a[i]-a[i-1];
		}
		b[s]++;
	}
	for(int i=1;i<=s;i++)
		mx=max(mx,b[i]);
	crystal(1);
	cout<<mx;
	return 0;
}
