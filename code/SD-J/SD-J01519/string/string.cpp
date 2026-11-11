#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
#define int unsigned long long
struct Node{
	char c;
	int beginning,ending;
}setc[N];
int n;
pair<int,char> T[N];
char setc_(int x){
	int i=1;
	while(setc[i].ending<x) i++;
	return i;
}
int check(int p){
	int i=1,j=p,cnt=0;
	while(i<=j){
		if(setc_(i)!=setc_(j)){
			cnt++;
		}
		i++,j--;
	}
	return cnt;
}
int gcd(int fn,int sn){
	if(sn==0) return fn;
	return gcd(sn,fn%sn);
}
int set_gcd(int p){
	int returning=T[1].first;
	for(int i=2;i<=p;i++){
		returning=gcd(returning,T[i].first);
	}
	return returning;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int cnt,p=0;
	char c,lastc='\0';
	for(int i=1;i<=n;i++){
		cin>>cnt>>c;
		if(c!=lastc) T[++p]={cnt,c},lastc=c;
		else T[p].first+=cnt;
	}
	if(p==1){
		cout<<"0\n";
		return 0;
	}
	int biggest_gcd=set_gcd(p);
	for(int i=1;i<=p;i++) T[i].first/=biggest_gcd;
	for(int i=1;i<=p;i++){
		setc[i].c=T[i].second;
		setc[i].beginning=setc[i-1].ending+1,setc[i].ending=setc[i-1].ending+T[i].first;
	}
	cout<<(check(setc[p].ending)*biggest_gcd)<<'\n';
	return 0;
}

