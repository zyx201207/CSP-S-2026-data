#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
struct stu{int zz,id;}sl[31],sl2[31];
int n,a[N],m,maxn;
int cf(int gs){
	int sumsum=1;
	for(int i=1;i<=gs;i++) sumsum*=2;
	return sumsum;
}
bool cmp(stu xx,stu yy){return xx.zz>yy.zz;}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;vector<int>tj[31],tj2[31];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		string ds="";int hhh=a[i];
		while(hhh!=0){
			if(hhh%2==1) ds+='1';
			else ds+='0';
			hhh/=2;
		}
		for(int j=0;j<=ds.size()-1;j++){
			if(ds[j]=='1'){
				tj[j+1].push_back(i);sl[j+1].zz++;
			}
		}
		maxn=max(a[i],maxn);
	}
	if(m==1) cout<<maxn;
	for(int i=1;i<=31;i++) sl[i].id=i;
	sort(sl+1,sl+32,cmp);
	if(sl[1].zz<m) cout<<0;
	else{
		int js=1,maxnn=0;
		while(sl[js].zz>=m&&js<=31) maxnn=max(sl[js++].id,maxnn);
		for(int i=1;i<=31;i++) sl2[i].id=i;
		for(int xxx=0;xxx<tj[maxnn].size();xxx++){
			string dsds="";int hhh=a[tj[maxnn][xxx]];
			while(hhh!=0){
				if(hhh%2==1) dsds+='1';
				else dsds+='0';
				hhh/=2;
			}
			for(int j=0;j<maxnn-1;j++){
				if(dsds[j]=='1'){
					tj2[j+1].push_back(xxx);sl2[j+1].zz++;
				}
			}
		}
		sort(sl2+1,sl2+maxnn,cmp);
		int jsjs=1,zhdlj=cf(maxnn-1);
		while(sl2[jsjs].zz>=m&&jsjs<maxnn){
			zhdlj+=cf(sl2[jsjs++].id-1);
		}
		cout<<zhdlj;
	}//4 2 3 15 12 12
	return 0;
}