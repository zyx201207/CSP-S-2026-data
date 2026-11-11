#include<bits/stdc++.h>
using namespace std;
int n,ansmax=0,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<string> vec(n+5);
	vector<string> vecans(n+10);
	int lincun;
	string lincun1;
	if(m!=1){
		for(int i=1;i<=n;i++){
			cin>>lincun;
			while(lincun!=0){
				lincun1+=48+lincun%2;
				lincun/=2;
			}
			vec[i]=lincun1;
			lincun1="";
		}
		if(m==n-1){
			
		}else if(m==2){
			
		}else if(m==n){
			for(int i=1;i<=n-1;i++){
				int vecilong=vec[i].size();
				int veci1long=vec[i+1].size();
				for(int j=0;j<=max(vecilong-1,veci1long-1);j++){
					if(vec[i][j]==vec[i+1][j] && vec[i][j]=='1'){
						vecans[i]+="1";
					}else{
						vecans[i]+="0";
					}
				}
			}
			for(int i=1;i<=n-1;i++){
				lincun1=vecans[i+1];
				vecans[i+1]="";
				int vecilong=vec[i].size();
				int veci1long=vec[i+1].size();
				for(int j=0;j<=max(vecilong-1,veci1long-1);j++){
					if(vecans[i][j]==lincun1[j] && vec[i][j]=='1'){
						vecans[i+1]+="1";
					}else{
						vecans[i]+="0";
					}
				}
			}
			int linjiwei=1;
			for(int i=0;i<=vecans[n-1].size();i++){
				if(vecans[n-1][i]=='1'){
					ansmax+=linjiwei;
				}
				linjiwei*=2;
			}
			cout<<ansmax;
			return 0;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>lincun;
			if(lincun>=ansmax){
				ansmax=lincun;
			}
		}
		cout<<ansmax;
		return 0;
	}
	return 0;
}
