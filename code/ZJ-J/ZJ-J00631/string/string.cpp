#include<bits/stdc++.h>
#include<string>
#define ll long long
using namespace std;
struct node{
	int id;
	int s;
	char ar;
};
int n,a[200010];
ll sum;
char ch[200010];
node f,e;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	f.s=a[1];
	f.ar=ch[1];
	f.id=1;
	e.ar=ch[n];
	e.s=a[n];
	e.id=n;
	while(f.id<e.id){
		if(f.ar!=e.ar){
			sum+=min(e.s,f.s);
		}
		f.s=max(0,f.s-e.s);
		e.s=max(0,e.s-f.s);
		if(f.s==0){
			f.id++;
			f.s=a[f.id];
			f.ar=ch[f.id];
		}
		if(e.s==0){
			e.id--;
			e.s=a[e.id];
			e.ar=ch[e.id];
		}
	}
	cout<<sum;
	return 0;
}