#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	ll num;
	char c;
}st[N];
int n;
ll sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x; char s;
		cin>>x>>s;
		st[i].c=s,st[i].num=x;
		sum+=x;	
	}
	ll zl=1,zr=n;
	ll suml=0,sumr=0;
	while(suml<=(sum+1)/2 && sumr<=(sum+1)/2){
		if(suml==(sum+1)/2&&sumr==(sum+1)/2) break;
		if(st[zl].num<st[zr].num && st[zl].num+suml<=(sum+1)/2){
			suml+=st[zl].num;
			st[zr].num-=st[zl].num;
			sumr+=st[zl].num;
			if(st[zl].c!=st[zr].c) ans+=st[zl].num;
			zl++;
		}else if(st[zl].num>st[zr].num && st[zr].num+suml<=(sum+1)/2){
			sumr+=st[zr].num;
			st[zl].num-=st[zr].num;
			suml+=st[zr].num;
			if(st[zl].c!=st[zr].c) ans+=st[zr].num;
			zr--;
		}else if(zl>=zr){
			break;
		}else if(st[zl].num==st[zr].num){
			suml+=st[zl].num;
			sumr+=st[zr].num;
			if(st[zl].c!=st[zr].c) ans+=st[zl].num;
			zl++,zr--;
		} 
	}
	cout<<ans<<"\n";
	return 0;	
}
