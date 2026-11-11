#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	a.push_back(0);
	b.push_back(0);
	int m,n,a1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1;
		a.push_back(a1);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<j;k++){
				if(b[k]==a[j]){
					for(int l=j-k;l>=0;l--){
						b.pop_back();
						b.push_back(a[j]);
					}
				}else{
					b.push_back(a[j]);
				}
			}
		}
		for(int j=1;j<=i;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
return 0;
}
