#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n],c[m]={0};
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
		vector <int> b;
		for(int j=i;j<n;j++){
			auto it=b.begin();
			for(it=b.begin();it<b.end();it++) if(b[*it]==a[j]){
				b.erase(it,b.end());
				break;
			}
			b.push_back(a[j]);
		}
		auto it=b.begin();
		for(it=b.begin();it<b.end();it++){
			for(int q=0;q<m;q++) if(b[*it]==q+1) c[q]++;
		}
	}
	for(int i=0;i<m;i++) cout<<c[i]<<" ";
	return 0;
}
