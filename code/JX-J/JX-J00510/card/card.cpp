#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int f[100005];
int find(int x,vector<int> p){
	int op=p.size();
	for(int i=0;i<op;i++){
		if(p[i]==x)return i;
	}
	return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
    if(m==1){
		cout<<1;
	}
	else{
		for(int i=0;i<n;i++){
			vector<int> p;
			for(int j=i;j<n;j++){
				int o=find(a[j],p);
				if(o!=-1)p.erase(p.begin()+o,p.end());
				p.push_back(a[j]);
			}
			for(int k=1;k<=m;k++)if(find(k,p)!=-1)f[k]++;
		}
		for(int k=1;k<=m;k++)cout<<f[k]<<' ';
	}
    return 0;
}
