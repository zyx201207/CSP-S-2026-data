#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],t;
map <int,int> mp,mpp,mmp;
map <int,int> mm;
map <int,bool> havem;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mm[a[j]]){
			    mm.clear();
			    mm[a[j]]=1;
			}else{
				mm[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(mm[havem[j]]) mp[havem[j]]++;
		}
	}
	cout<<0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mmp[j]){
				mmp[j];
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
