#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	int n,m;
	fin>>n>>m;
	vector<int> a(n+1),t(m+1,0);
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> c;
		for(int j=i;j<=n;j++){
			for(int k=0;k<c.size();k++){
				if(a[j]==c[k]){
					int m=c.end()-c.begin()-k;
					c.erase(c.begin()+k,c.end());
					k=m;
				}
			}
			c.push_back(a[j]);
		}
		sort(c.begin(),c.end());
		c.erase(unique(c.begin(),c.end()),c.end());
		for(int x:c){
			t[x]++;
		}
	}
	for(int x=1;x<=m;x++){
		fout<<t[x]<<" ";
	}
	return 0;
}