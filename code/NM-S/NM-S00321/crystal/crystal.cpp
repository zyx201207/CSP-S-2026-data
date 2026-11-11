#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		int n,m,q=0,f=0,ffl=0;
		cin>>n>>m;
		if(n==1){
			cout<<1;
			return 0;
		}
		if(m==0)f=1;
		int a[n+5]{},c[n-5]{},e[9999]{},fe[9999]{};
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>=0)
			e[a[i]]++;
			else fe[abs(a[i])]++;
			if(a[i]!=i)ffl=1;
		}
		if(ffl==0){
			for(int i=1;;i++){
				if(m>=i){
					m-=i;
					q++;
				}
				cout<<q;
				return 0;
			}
		}
		if(f){
			sort(e,e+9999,cmp);
			sort(fe,fe+9999,cmp);
			if(e[0]>=fe[0])cout<<e[0];
			else cout<<fe[0];
			return 0;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			c[i]=a[i]-a[i-1];
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(m>0){
				m-=abs(c[i]);
				q++;
			}
			else break;
		}
		cout<<q;
		return 0;
	}
