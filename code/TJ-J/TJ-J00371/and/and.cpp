#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
vector<int>v[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v[31].push_back(x);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int k=0,s=1<<i,d;
		for(vector<int>::iterator j=v[i+1].begin();j!=v[i+1].end();j++){
			if((*j&s)==s){
				v[i].push_back(*j);
				k++;
			}
		}
		if(k<m){
			v[i]=v[i+1];
		}else{
			ans|=s;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
