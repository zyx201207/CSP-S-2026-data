#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
const int M=3e5+5;
ll n,m,a[N],ans[M];
vector<ll> vec;
int find(int a){
	for(int i=0;i<vec.size();i++){
		if(vec[i]==a){
			return i;
		}
	}
	return 0;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);   
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(find(a[j])==0){
				vec.push_back(a[j]);
			}else{
				for(int k=find(a[j]);k<vec.size();k++){
					vec.pop_back();
				}
			}
		}
		for(int k=0;k<vec.size();k++){
			ans[vec[k]]++;
		}
		while(!vec.empty()){
			vec.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
