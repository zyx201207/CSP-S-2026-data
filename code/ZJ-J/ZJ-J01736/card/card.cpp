#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	vector<int>table(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool imf=1;
			for(int k=1;k<=n;k++){
				if(a[i]==table[k]){
					imf=0;
					int p=n-k+1;
					while(p--)table.pop_back();
				}
			}
			if(imf)table.push_back(a[j]);
		}
		for(auto &x:table){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
