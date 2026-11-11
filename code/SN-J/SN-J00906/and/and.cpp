#include<bits/stdc++.h>
using namespace std;
int _and=0;
const int maxn=200001;
int a[maxn];
int b[maxn];//二进制 
string cnt;
int cnt1;
string er(int x){
	string js;//half 结果 string
	string js1;//end string
	while(x!=0){
		int y=x%2;
		x/=2;
		y+='0';
		js+=y;
	}
	for(int i=js.size(),j=1;i>=1,j<=js.size();i--,j++){
		js1[j]=js[i];
	}
	return js1;
}
int ad(int x,int y){
	if(x==y&&x!=0&&y!=0){
		return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int ers=ad(b[i],b[j]);
			_and=max(ers,_and);
		}
	}
	_and+='0';
	for(int i=_and.size();i>=1 ;i--){
		for(int j=1;j<=_and.size();j++){
		    int mas=1;//位权
		    if(j==0){
			    mas=1;
		    } 
		    else{
		        for(int k=1;k<=j;k++){
			        mas*=2;
		        } 
	        }
	        cnt1+=(_and[i]*mas);	
		}
	}
	cout<<cnt1;
	return 0;
}
