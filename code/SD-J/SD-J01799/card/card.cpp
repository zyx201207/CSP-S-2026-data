#include<iostream>
using namespace std;
int sss[3005];
int nn,mm;
int aaa[205][205],bbb[2005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>nn>>mm;
	for(int i=1;i<=nn;i++){
		cin>>aaa[0][i];
		for(int j=1;j<nn;j++){
			aaa[j][i]=aaa[0][i];
		}
	}
	for(int i=1;i<=nn;i++){
		int kk=1,flag;
		for(int j=i;j<=nn;j++){
			flag=1;
			for(int h=1;h<=kk;h++){
				if(aaa[i][j]==bbb[h]){
					kk=1;
					flag=0;
					break;
				}
			}
			if(flag==1){
				bbb[kk++]=aaa[i][j];
			}
		}
		for(int j=1;j<kk;j++){
			sss[bbb[j]]++;
		}
	}
	for(int j=1;j<=mm;j++){
		cout<<sss[j]<<" ";
	}
	return 0;
}
