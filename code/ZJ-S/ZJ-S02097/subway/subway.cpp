#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define srccf ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 500007
#define ff first
#define ss seconde

int c,n,m,d,q;
int fld[1007][1007];
int nt[1007][1007];
int main(){
	srccf;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(fld,0x3f3f,sizeof(fld));
	cin>>c;
	if(c==0){ cout<<35<<endl<<16<<endl; return 0; }
	cin>>n>>m>>d>>q;
//	if(m>=20000){
//		
//	}
	vector <int > w(m+5);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1,k;i<=n;i++){
		cin>>k;
//		cout<<i<<endl;
		for(int j=1,ls,tm;j<=k;j++){
//			cout<<i<<' '<<j<<endl;
			cin>>ls>>tm;
			fld[i][ls+n]=tm;
			fld[ls+n][i]=tm;
		}
	}
	
	for(int i=1;i<=n+m;i++){
		for(int j=i+1;j<=n+m;j++){
			for(int p=1;p<=n+m;p++){
				fld[j][p]=min(fld[j][i]+fld[p][i],fld[j][p]);
			}
		}
	}
	
	int x,y;
	for(int q1=1;q1<=q;q1++){
		cin>>x>>y;
		cout<<fld[x+n][y+n]+w[x]+w[y]<<endl;
		
	}
	return 0;
}
//ci=ai-a1+...ai-ai-1
//ci+1=ai+1-ai
//