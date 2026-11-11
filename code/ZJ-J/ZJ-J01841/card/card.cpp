#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a;vector<int> p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;p.resize(m);
	for(int i=0;i<n;i++){int tmp;cin>>tmp;a.push_back(tmp);}
	for(int i=0;i<n;i++){
		vector<int> b;
		for(int j=i;j<n;j++){//after i
			for(int k=0;k<b.size();k++){
				if(a[j]==b[k]){
					b.resize(k);
					break;
				}
			}b.push_back(a[j]);
			//for(int k:b) cout<<k<<' ';cout<<endl;
		}for(int j:b) p[j-1]++;
	}ll Last=p[p.size()-1];
	p.pop_back();
	for(int i:p)cout<<i<<' ';
	cout<<Last<<'\n';
	return 0;
}