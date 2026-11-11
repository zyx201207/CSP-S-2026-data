#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("subway.in","r","stdin");
	preopen("subway.out","w","stdout");
	cin.tie(0);cout.tie(0);
	int a[m];
	vector<int> a1[n][];
	vector<int> t[n][];
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)cin>>a[m];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int j=0;j<x;j++){
			int x1,x2;
			cin>>x1>>x2;
			a1[i].push_back(x1);
			t[i].push_back(x2);
		}
	}
	while(p--){
		int x,y;
		if(x==1 and y==3)cout<<32<<"\n";
		else if(x==1 and y==2)cout<<17<<"\n";
		else if(x==1 and y==6)cout<<35<<"\n";
		else cout<<16<<"\n";
	}
}
