#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			f=0;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector <long long> v;
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
		}
		for(int j=i;j<=n;j++){
			bool ff=0;
			long long k=1;
			for(auto it:v){
				if(it==a[j]){
					ff=1;
				}
				if(ff){
					k--;
					v.erase(v.begin()+k);
				}
				k++;
			}
			v.push_back(a[j]);
		}
		for(auto it:v){
			cnt[it]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
//±©Á¦ 
/*
4 3
1 2 1 3

3 1 4
---------
10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
