#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
char s1[maxn],c1[maxn],s2[maxn],c2[maxn];
bool same(char x[],char y[],int f,int b){
	for(int i=f;i<=b;i++)if(x[i]!=y[i])return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1+1>>c1+1>>s2+1>>c2+1;
	if(same(s1,s2,1,2))cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(same(c1,c2,1,2))cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((c1[3]<='C')==(c2[3]<='C'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(c1[3]-c2[3]>=-1&&c1[3]-c2[3]<=1)cout<<"1";
	else cout<<"0";
	return 0;
}