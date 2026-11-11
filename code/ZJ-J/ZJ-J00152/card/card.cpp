#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
map<int,int> ma;
map<int,int> cs;
vector<int> v;
void eras(int be,int wz){
//	iterator it:v;
//	v.erase(it+be,it+be+en-1);
for(int i=be;i<=wz;i++){
	ma[v[i]]=0;
}
	v.erase(v.begin()+be,v.end());
}
void fp(int i){
	v.clear();
	v.push_back(0);
	int wz=1; 
	for(int j=i;j<=n;j++){
		
		if(ma[a[j]]==0){

			v.push_back(a[j]);
			ma[a[j]]=wz;
		}
		else{
			int ls=ma[a[j]];
			eras(ma[a[j]],wz);
			wz=ls;
			v.push_back(a[j]);
			ma[a[j]]=wz;
		}
		wz++;
		
	}
	for(int k=1;k<wz;k++){

		cs[v[k]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}

	for(int i=1;i<=n;i++){
		ma.clear();
		fp(i);
	}
	for(int i=1;i<=m;i++) cout<<cs[i]<<" ";
	return 0;
}
