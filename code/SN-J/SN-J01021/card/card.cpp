// SN-J01021 Ê¦´ó01¿¼³¡  ³Â¼ÎÏé 
#include<bits/stdc++.h>
using namespace std;
int n,m,s,l;
vector<int>a;
int aa[300005];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>t;
		for(int k=i;k<=m;k++){
			bool f=0;
			l=t.size();
			for(int j=1;j<=l;j++){
				if(j==a[k]){
					f=1;
					s=j;
					break;
				}
			}
			if(f==1)
				t.erase(t.begin()+s,t.end());
			t.push_back(a[k]);
		}
		int l=t.size();
		for(int j=1;j<=m;j++){
			for(int k=1;k<=l;k++){
				if(t[k]==j) aa[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",aa[i]);
	return 0;
}
