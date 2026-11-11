#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	vector<int> a,b;
	map<int,int> mp1;
	vector<int> c(m+1);
	for(int i =0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);	
	}
	for(int p=0;p<n;p++){
		int len = a.size();
		b.clear();
		mp1.clear();
		for(int i =0;i<len;i++){
			b.push_back(a[i]);
			++mp1[a[i]];
			if(mp1[a[i]]==2){
				b.erase(b.end()-1);
				--mp1[a[i]];
				while(b[b.size()-1]!=a[i]){
					//cout<<b[b.size()-1]<<endl;
					--mp1[b[b.size()-1]];
					b.erase(b.end()-1);
				}
			}
		}
		for(int i = 0;i<b.size();i++){
			++c[b[i]];
		}
		a.erase(a.begin());
	}
	for(int i = 1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	cout<<endl;
	return 0;
}
