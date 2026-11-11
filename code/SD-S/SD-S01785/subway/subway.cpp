#include<bits/stdc++.h>
using namespace std;
int sj[500009];
int lx[509][500009];
struct stu{
	int l;
	int cs[500009];
	int jj[500009];
};
stu s[5009];
int main(){
	
//	ios::sync_with_stdio(0);cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q,sl;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sj[i];
	}
	for(int i=1;i<=n;i++){
		cin>>sl;
		s[i].l=sl;
		for(int j=1;j<=sl;j++){
			cin>>s[i].cs[i]>>s[i].jj[i];
		}
	}
	int cf,zz;
	int sum=0;
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>cf>>zz;
		sum+=sj[cs]+sj[zz];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=s[j].l;k++){
				if(s[k].cs==cf or s[k].cs==zz){
					sum+=s[k].jj;
				} 
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
