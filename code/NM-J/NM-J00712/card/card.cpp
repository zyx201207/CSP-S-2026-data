#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> desk;
bool find(vector<int> d,int x){
	for(int i=0;i<d.size();i++){
		if(d[i]==x){
			return 1;
		}
	}
	return 0;
}
int t[500005];
int f(vector<int> d,int x){
	for(int i=0;i<d.size();i++){
		if(d[i]==x){
			return i;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(!find(desk,a[i])){
				desk.push_back(a[i]);
			}
			else{
				desk.clear();
				desk.push_back(a[i]);
			}
		}
		for(int j=0;j<desk.size();j++){
			t[j]++;
		}
	}

	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
