#include <bits/stdc++.h>
using namespace std;
struct s{
	long long l;
	char c;
}a[100099];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N,p=1;
	cin>>N;
	for(int i=0;i<N;i++){
		long long L;
		char C;
		cin>>L>>C;
		if(C==a[p-1].c)a[p-1].l+=L;
		else{a[p].l=L;a[p].c=C;p++;}
	}
	int L=1,R=p-1;
	long long need=0;
	while(R!=L){
		if(a[R].l>a[L].l){
			a[R].l-=a[L].l;
			if(a[R].c!=a[L].c)need+=a[L].l;
			L++;
		}
		else{
			a[L].l-=a[R].l;
			if(a[R].c!=a[L].c)need+=a[R].l;
			R--;
		}
	}
	cout<<need;
	return 0;
}
