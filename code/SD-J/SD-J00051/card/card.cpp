#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],r[N],res[N],ri=0;
map<int,int>mp,mk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;bool f=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i&&a[i]<a[i-1])f=0;
	}
	if(f){
		for(int i=0;i<n;i++){
			ri=0;
			for(int j=i;j<n;j++){
				if(a[j-1]!=a[j]){
					r[ri]=a[j];ri++;
				}				
			}
			for(int j=0;j<ri;j++){
				res[r[j]]++;
			}
		}	
		for(int k=1;k<=m;k++)cout<<res[k]<<" ";cout<<"\n";
	}else{
		for(int i=0;i<n;i++){
			ri=0;mp.clear();mk.clear();
			for(int j=i;j<n;j++){
				if(mp[a[j]]>0){
					ri=mk[a[j]]+1;
				}else{
					mk[a[j]]=ri;mp[a[j]]++;
					r[ri]=a[j];ri++;
				}				
			}
			for(int j=0;j<ri;j++){
				res[r[j]]++;
			}
		}		
		for(int k=1;k<=m;k++)cout<<res[k]<<" ";cout<<"\n";
	}
	return 0;
}
