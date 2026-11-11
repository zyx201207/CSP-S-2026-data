#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200001],m,cf[31],d[200001];
vector<int > p[200001],mm[3];

void ddd(int x){
	int bb=0,ll=a[x];
	while(ll){
		bb=ll%2;
		ll=ll/2;  
		p[x].push_back(bb);
	}
return ;	
}

void ejz(int x,int y){
	int bb=0,ll=x;
	while(ll){
		bb=ll%2;
		ll=ll/2;
		mm[y].push_back(bb);
	}
return ;	
}

int sjz(int y ){
	int ll=0,bb=0;
	for(int i=0;i<mm[y].size();i++)
	{
		ll=mm[y][i]*cf[i];
		bb+=ll;
	}
	return bb;
}

int yu(int x,int y){
	ejz(x,1);
	int mmm=min(mm[1].size(),p[y].size()),ml=max(mm[1].size(),p[y].size());

	for(int i=0;i<mmm;i++)
	{
		mm[2][i]=(mm[1][i]||p[y][i]);
	}
	if(mm[1].size()>p[y].size()){
	
	for(int i=mmm;i<ml;i++){
		mm[2][i]=mm[1][i];
	}
}
	else{
		for(int i=mmm;i<ml;i++){
		mm[2][i]=p[y][i];
	}
	}
	for(int i=0;i<mm[2].size();i++){
		cout<<mm[2][i];
	}
	cout<<endl;
	return sjz(2);
}



signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ddd(i);
	}
	cf[0]=1;
	for(int i=1;i<=30;i++)
	{
		cf[i]=cf[i-1]*2; 
	}
	
	d[1]=a[1];
	cout<<yu(d[1],2)<<endl<<111111;
//	for(int i=2;i<=n;i++)
//	{
//		for(int j=1;j<=m&&j<=n;j++)
//		{
//			
//		}
//	}
	
	return 0;
}


 
