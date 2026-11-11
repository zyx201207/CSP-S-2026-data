#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a,c;
	bool cnt;
}b[202610][33];
bool cmp(node aa,node bb){
	return aa.c>bb.c||aa.c==bb.c&&aa.a>bb.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i][0].a;
		int k=32;
		int aaa=b[i][0].a;
		while(aaa>0){
			int r=aaa%2;
			aaa/=2;
			if(r==1){
				b[i][k].cnt=1;
				b[i][0].c++;
			}
			k--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j][0].c>b[i][0].c||b[j][0].c==b[i][0].c&&b[j][0].a>b[i][0].a){
				swap(b[j][0].c,b[i][0].c);
				swap(b[j][0].a,b[i][0].a);
				swap(b[j][0].cnt,b[i][0].cnt);
				swap(b[j][1].cnt,b[i][1].cnt);
				swap(b[j][2].cnt,b[i][2].cnt);
				swap(b[j][3].cnt,b[i][3].cnt);
				swap(b[j][4].cnt,b[i][4].cnt);
				swap(b[j][5].cnt,b[i][5].cnt);
				swap(b[j][6].cnt,b[i][6].cnt);
				swap(b[j][7].cnt,b[i][7].cnt);
				swap(b[j][8].cnt,b[i][8].cnt);
				swap(b[j][9].cnt,b[i][9].cnt);
				swap(b[j][10].cnt,b[i][10].cnt);
				swap(b[j][11].cnt,b[i][11].cnt);
				swap(b[j][12].cnt,b[i][12].cnt);
				swap(b[j][13].cnt,b[i][13].cnt);
				swap(b[j][14].cnt,b[i][14].cnt);
				swap(b[j][15].cnt,b[i][15].cnt);
				swap(b[j][16].cnt,b[i][16].cnt);
				swap(b[j][17].cnt,b[i][17].cnt);
				swap(b[j][18].cnt,b[i][18].cnt);
				swap(b[j][19].cnt,b[i][19].cnt);
				swap(b[j][20].cnt,b[i][20].cnt);
				swap(b[j][21].cnt,b[i][21].cnt);
				swap(b[j][22].cnt,b[i][22].cnt);
				swap(b[j][23].cnt,b[i][23].cnt);
				swap(b[j][24].cnt,b[i][24].cnt);
				swap(b[j][25].cnt,b[i][25].cnt);
				swap(b[j][26].cnt,b[i][26].cnt);
				swap(b[j][27].cnt,b[i][27].cnt);
				swap(b[j][28].cnt,b[i][28].cnt);
				swap(b[j][29].cnt,b[i][29].cnt);
				swap(b[j][30].cnt,b[i][30].cnt);
				swap(b[j][31].cnt,b[i][31].cnt);
				swap(b[j][32].cnt,b[i][32].cnt);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=32;i++){
		int zhi=0;
		bool flag=1;
		for(int j=1;j<=m;j++){
			if(b[j][i].cnt==0){
				flag=0;
				break;
			}
		}
		if(flag==1){
			zhi=1;
			for(int j=1;j<=32-i;j++){
				zhi*=2;
			}
		}
		ans+=zhi;
	}
	cout<<ans;
}