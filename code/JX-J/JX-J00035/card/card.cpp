#include <bits/stdc++.h>
using namespace std;

const int N1=5e5+10,N2=5e3+10;
int a[N1],t[N2],c[N2];
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		memset(c,0,sizeof c);
		while (s.size()) s.pop();
		for (int j=i;j<=n;j++){
			if (c[a[j]]){
				int siz=s.size();
				while (siz>c[a[j]]){
					c[s.top()]=0,siz--;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				c[a[j]]=s.size();
			}
		}
		while (s.size()){
			t[s.top()]++;
			s.pop();
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",t[i]);
}
