#include<bits/stdc++.h>
using namespace std;
long long car[500010];
long long typ[500010];
long long huancun[500010];
long long n,m;
void count(long long zuobiao){
	for(int i=1;i<=m;i++){
		huancun[i]=0;
	}
	for(int i=zuobiao+1;i<=n;i++){
		huancun[car[i]]=1;
	}
	for(int i=1;i<=m;i++){
		typ[i]+=huancun[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>car[i];
	}
	for(int i=1;i<=n;i++){
		count(i);
	}
	for(int i=1;i<=m;i++){
		cout<<typ[i];
	}
	
	return 0;
}