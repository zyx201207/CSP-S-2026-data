#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e4+5;
vector <int> v[MAXN];
int c,n,m,d,q,w[MAXN];
vector <int> t[505],a[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		t[i].push_back(0);
		a[i].push_back(0);
		for(int j=1;j<=k;j++){
			int A,T;
			cin>>A>>T;
			t[i].push_back(T);
			a[i].push_back(A);
			v[A].push_back(i);
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		for(int i=0;i<v[e].size();i++){
			
		}
	}
	return 0;
}
/*











终于轮到我了吗。。。。。。 
AFOed...
大梦初醒罢了
我该在哪里停留我问我自己 --2026-10-31 17:50


       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																								
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
       																									
*/
