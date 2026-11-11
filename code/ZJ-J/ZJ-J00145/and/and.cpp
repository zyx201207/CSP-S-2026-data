#include<bits/stdc++.h>
using namespace std;
int n,m;
struct twoj{
	long long a;
	string s;
	long long l;
}b[200005];
string two(int n){
	string x;
	while(n>0){
		if(n%2==1) x+='1';
		else x+='0';
		n/=2;
	}
	return x;
}
bool sortb(twoj x,twoj y){
	return x.a>y.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i].a;
		b[i].s=two(b[i].a);
		b[i].l=b[i].s.size();	
	}
	sort(b+1,b+n+1,sortb);
	long long lz=2000000000000000005;
	for(int i=1;i<=m;i++) lz=min(lz,b[i].l);
	string z;
	for(int j=1;j<=lz;j++){
		int flag=1;
		for(int i=1;i<=m;i++){
			char d=(b[i].s)[j-1];
			if(d=='0') flag=0;
		}
		if(flag==1)z+='1';
		else z+='0';
	}
	long long ans=0;
	int w=1;
	for(int i=0;i<z.size();i++){
		ans+=(int(z[i])-48)*w;
		w*=2;
	}
	cout<<ans;
	return 0;
}
