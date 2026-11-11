#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int a[N],b[N];
string xiang1,xiang2,zuo1,zuo2,pai1,pai2;
char ce1,ce2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['A']=0;
	a['B']=0;
	a['C']=0;
	a['D']=1;
	a['E']=1;
	b['A']=1;
	b['B']=2;
	b['C']=1;
	cin>>xiang1>>zuo1>>xiang2>>zuo2;
	if(xiang1==xiang2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	pai1=zuo1[0]+zuo1[1];
	pai2=zuo2[0]+zuo2[1];
	if(pai1==pai2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	ce1=zuo1[2];
	ce2=zuo2[2];
	if(a[(int)ce1]==a[(int)ce2]) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(a[(int)ce1]==1&&a[(int)ce2]==1) cout<<1;
	else if(b[(int)ce1]+b[(int)ce2]==3) cout<<1;
	else cout<<0;
	return 0;
}
