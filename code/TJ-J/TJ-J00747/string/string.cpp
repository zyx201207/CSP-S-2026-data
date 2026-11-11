#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+10;
ll n,ans=0;
ll tot=0;
string s="";
struct ss{
	int num;
	string tmp;
}zf[N];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>zf[i].num>>zf[i].tmp;
		tot+=zf[i].num;
	}
	ll l=1,r=tot; 
	ll zl=1,zr=n; 
	while(l<r){
		if(zf[zl].tmp!=zf[zr].tmp){
			if(zf[zl].num<zf[zr].num){
				l+=zf[zl].num;
				ans+=zf[zl].num;
				zf[zr].num-=zf[zl].num;
				r-=zf[zl].num;
				zf[zl].num=0;
				zl++; 
			}
			else if(zf[zl].num==zf[zr].num){
				l+=zf[zl].num;
				r-=zf[zr].num;
				ans+=zf[zl].num; 
				zf[zl].num=zf[zr].num=0;
				zl++;
				zr--;
			}
			else{
				r-=zf[zr].num;
				l+=zf[zr].num;
				ans+=zf[zr].num;
				zf[zl].num-=zf[zr].num; 
				zf[zr].num=0;
				zr--;
			}
		}
		else{
			if(zf[zl].num<zf[zr].num){ 
				l+=zf[zl].num;
				zf[zr].num-=zf[zl].num; 
				r-=zf[zl].num;
				zf[zl].num=0;
				zl++;
			}
			else if(zf[zl].num==zf[zr].num){
				l+=zf[zl].num;
				r-=zf[zr].num;
				zf[zl].num=zf[zr].num=0;
				zl++;
				zr--;
			}
			else{ 
				r-=zf[zr].num;
				l+=zf[zr].num;
				zf[zl].num-=zf[zr].num; 
				zf[zr].num=0;
				zr--;
			}
		}
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
