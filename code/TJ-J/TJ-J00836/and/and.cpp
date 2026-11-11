#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	int num=v.size();
	int j=1;
	int ans=v[0];
/*	for(int i=1;i<n;i++){
		if(j>m){
			break;
		}
		if(v[i]&ans>=min(v[i],ans)){
			ans&=v[i];
			j++;
		}
	}*/
	cout<<ans;
	return 0;
} 
