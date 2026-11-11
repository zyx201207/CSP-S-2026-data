#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,x[N],y[N],ans,h,p;
char t[N];
map<long long,char> m;
set<long long> s;
void maind(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>t[i];
		h+=x[i];
		y[n-i+1]=x[i];
	}
	for(int i=1;i<=n;i++){
		p+=x[i];
		if(p>=h/2){
			s.insert(h/2);
			break;
		}
		else s.insert(p);
	}
	p=0;
	for(int i=n;i>=1;i--){
		p+=x[i];
		if(p>=h/2) break;
		else s.insert(p);
	}
	s.insert(0);
	long long u=0;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]+x[i];
		y[i]=y[i-1]+y[i];
	}
	for(auto i:s){
		if(i!=0){
			int a=lower_bound(x+1,x+1+n,i)-x;
			int b=lower_bound(y+1,y+1+n,i)-y;
			if(t[a]!=t[n-b+1]){
				ans+=i-u;
			}
		}
		u=i;
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

