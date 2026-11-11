#include<bits/stdc++.h>
using namespace std;
struct Edge{
	long long x,y,v;
}b[500010];
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
map<long long,long long>c;
long long a[500010],cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i].x=a[i+1];
		b[i].y=a[i];
		b[i].v=a[i+1]-a[i];
	}
	sort(b+1,b+n,cmp);
	for(int i=1;i<n;i++){
		if(m>=c[b[i].y]*b[i].v){
			if(b[i].x!=b[i].y){
				c[b[i].x]+=c[b[i].y];
			}
			if(c[b[i].x]>cnt){
				cnt=c[b[i].x];
				m-=c[b[i].y]*b[i].v;
			}
			//cout<<b[i].y<<" "<<b[i].x<<" "<<c[b[i].y]<<" "<<c[b[i].x]<<" "<<b[i].v<<" "<<m<<" "<<cnt<<"^^"<<endl;
		}else{
			break;
		}
	}
	cout<<cnt;
	return 0;
}

