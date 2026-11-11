#include<bits/stdc++.h>
using namespace std;
int cjj_x[2000005],chenchenkx[2000005],zwt_ak_csp=0;
int cjj_c,cjj_t,cjj_n,cjj_d;
void A01(){
	for(int i=1;i<=cjj_n;i++){
		chenchenkx[i]=0;
	}
	chenchenkx[1]=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cjj_c>>cjj_t;
	while(cjj_t--){
		zwt_ak_csp=0;
		cin>>cjj_n>>cjj_d;
		for(int i=1;i<=cjj_n;i++){
			cin>>cjj_x[i];
		}
	    A01();
	    for(int i=1;i<=cjj_n;i++){
	    	int wyz_ak_csp=1;
	    	while(i-wyz_ak_csp>0&&cjj_d>=cjj_x[i]-cjj_x[i-wyz_ak_csp]){
				wyz_ak_csp++;
			}
			chenchenkx[i]+=chenchenkx[wyz_ak_csp];
			if(chenchenkx[i]==2)zwt_ak_csp++;
		}
		cout<<zwt_ak_csp<<endl; 
	}
	return 0;
} 
