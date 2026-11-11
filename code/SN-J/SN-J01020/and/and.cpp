#include <bits/stdc++h>
using namespace std;
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}for(int i=0;i<n;i++){
		for(int j=0j<n;j++){
			if(v[j]<v[j+1]){
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	int a=v[0];
	for(int i=1;i<=m;i++){
		a=v[i]`a;
	}
}
