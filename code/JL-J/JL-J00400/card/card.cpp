
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[10000],b[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack <int> s;
	vector <int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int x=0;x<n;x++){
			s.push(a[i]);
			for(int j=0;j<n;j++){
				if(v[j]==s.top()){
					v.clear();
				}
				v.push_back(a[i]);
			}
			for(int y=0;y<=n;y++){
				b[v[i]]++;
			}
		}
		
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
