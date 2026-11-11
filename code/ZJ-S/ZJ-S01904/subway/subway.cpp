#include<bits/stdc++.h>
using namespace std;
long long cjj_is_furry[505][505];
long long chenchenkx[500005],ch[500005];
const int cjj_INTMAX=2147483645;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=505;i++){
		for(int j=0;j<=505;j++){
			cjj_is_furry[i][j]=cjj_INTMAX;
		}
	}
	int cjj_c,cjj_n,cjj_m,cjj_d,cjj_q;
	cin>>cjj_c>>cjj_n>>cjj_m>>cjj_d>>cjj_q;
	int cjj_w[505];
	for(int i=1;i<=cjj_m;i++){
		cin>>cjj_w[i];
	}
	for(int i=1;i<=cjj_n;i++){
		int cjj_k;
		cin>>cjj_k;
		for(int j=1;j<=cjj_k;j++){
			cin>>chenchenkx[j]>>ch[j];
		}
		for(int j=1;j<=cjj_k;j++){
			for(int z=1;z<=cjj_k;z++){
				cjj_is_furry[chenchenkx[j]][chenchenkx[z]]=ch[j]+ch[z];
				cjj_is_furry[chenchenkx[z]][chenchenkx[j]]=ch[j]+ch[z];
			}
		}
	}
	for(int i=1;i<=cjj_m;i++){ 
		for(int j=i;j<=cjj_m;j++){
			for(int z=1;z<=cjj_m;z++){
				if(cjj_is_furry[i][z]+cjj_is_furry[z][j]<cjj_is_furry[i][j]){
					cjj_is_furry[i][j]=cjj_is_furry[i][z]+cjj_is_furry[z][j];
					cjj_is_furry[j][i]=cjj_is_furry[i][z]+cjj_is_furry[z][j];
				}
			}
		} 
	} 
	for(int i=1;i<=cjj_q;i++){
		int x,y;
		cin>>x>>y;
		cout<<cjj_is_furry[x][y]+cjj_w[x]+cjj_w[y]<<endl;
	}
	return 0;
}
