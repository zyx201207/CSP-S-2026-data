#include <bits/stdc++.h>
using namespace std;
// 注释记得去掉 检查 
const int N = 2e5+8;
long long n,m;
struct Ww{
	long long a,z;
};
Ww p[N];
bool cmp(Ww b,Ww y){
	if(b.z>y.z)return true;
	else if(b.z==y.z){
		if(b.a>y.a)return true;
		else return false;
	}
	else return false;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> p[i].a;
		long long x = p[i].a;
		while(x>0){
			if(x%2==1)p[i].z++;
			x/=2;
		}
	}
	sort(p+1,p+1+n,cmp);
	if(m==1){
		cout << p[1].a;
		return 0;
	}
	long long x = p[1].a;
	for(long long i=2;i<=m;i++){
		x&=p[i].a;
	}
	cout << x;
	
	
	return 0;
}
