#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long tong[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>s(n);
		for(int j=i;j<=n;j++){
			for(int k=1;k<=s.size();k++){
				if(s[k]==a[j]){
				    s[a[j]-1]=0;
			    }
			}
			s.push_back(a[j]);
		}
		for(int j=1;j<=n;j++){
			tong[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
