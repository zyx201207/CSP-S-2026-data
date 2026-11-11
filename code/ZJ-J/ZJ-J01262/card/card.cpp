#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool xydy=true;
map<int,bool>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			xydy=false;
		}
	}
	if(xydy){
		for(int i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int>vec;
		for(int j=i;j<=n;j++){
			if(count(vec.begin(),vec.end(),a[j])==0){
				vec.push_back(a[j]);
			}else{
				while(vec.back()!=a[j]){
					vec.pop_back();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(count(vec.begin(),vec.end(),j)!=0){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}