

#include<bits/stdc++.h>
using namespace std;
int n,m,qwe[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> a;
	int c;
	while(cin>>c){
		a.push_back(c);
	}
	for(int i=0;i<n;i++){
		vector<int> b(a.begin(),a.end())
		for(int j=b.size()-1;j>i;j--){
			for(int q=b.size()-2;q>=i;q--){
				if(b[j]==b[q]){
					for(int p=q;p>=0;p--){
						b[p]=-1;
					}
					break;
				}
			}
			if(b[j]==-1) break;
		}
		for(int j=1;j<m;j++){
			for(int q=i;q<b.size();q++)
				if(b[q]==j){
					qwe[j]++;
					break;
				}
		}
	}
	for(int i=0;i<m;i++){
		cout<<qwe[i]<<' ';
	}
	return 0;
}


