#include<cstdio>
#include<vector>
using namespace std;
int w[500005];
vector <int> a[505], t[505], to[50505], l[50505];
int main(){
	int C, n, m, d, q, k[505], o, p, ta, tt;
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &q);
	for(int i=1;i<=m;i++){
		scanf("%d", &w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d", &ta, &tt);
			a[i].push_back(ta);
			t[i].push_back(tt);
			to[i+m].push_back(ta);
			to[ta].push_back(i+m);
			l[i+m].push_back(tt);
			l[tt].push_back(i+m);
		}
	}
	while(q--){
		scanf("%d%d", &o, &p);
		"操他妈的老子只会写输入，这几把S考得老他妈是没见过的，去年难今年怎么还他妈是这样，考，考集贸，我高中毕业都考不过。 ";
	}
	return 0;
}
