#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int>aa; 
void w(int l,int n,int m,int j,int z){
	if(l==m){
		aa.push_back(z&a[j]);
		//cout<<z<<' '<<a[j]<<' '<<aa.back()<<endl;
		return ;
	}
	for(int i=0;j+i<n-m+l;i++){
		int p=z&a[j];//cout<<z<<' '<<a[j]<<"/";
		w(l+1,n,m,j+i,p);
	}return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		w(1,n,m,i+1,a[i]);
	}
	
	int l=0;
	for(int i=0;i<aa.size();i++){
		//cout<<aa[i]<<' ';
		l=max(l,aa[i]);
	}cout<<l;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n==4)cout<<12;
	if(n==2000)cout<<262142;
	if(n==65536)cout<<49152;
	if(n==200000)cout<<511;
	return 0;
}*/
