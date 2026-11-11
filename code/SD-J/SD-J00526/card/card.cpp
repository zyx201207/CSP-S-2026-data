//card
//10:51 ln D
//10:54 wa on D
//10:55 leave D
//11:00 backt D
//11:14 leave D
//11:20 backt D
//11:40 partc D
#include<iostream>
using namespace std;
//#define freopon freopen
//#define freapon freopen
int n,m,a[500005],ans[500005];
int main(){
//	freapon("card.in","r",stdin);
	freopen("card,in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int ln=1,rn=1,temp[500005];
		for(int j=i;j<=n;j++){//²åÈëa[j] 
			bool rnchange=0;
			for(int k=ln;k<=rn;k++){
				if(temp[k]==a[j]){
					rn=k;
					rnchange=1;
					break;
				}
			}if(!rnchange){
				rn++;
				temp[rn]=a[j];
			}
		}for(int j=1;j<=m;j++){
			for(int k=ln;k<=rn;k++){
				if(temp[k]==j){
					ans[j]++;
				}
			}
		}
	}for(int i=1;i<=50005;i++){
		if(ans[i]!=0){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
