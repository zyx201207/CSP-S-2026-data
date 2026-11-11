#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[500005];
int c[500005];
signed main(){
  	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		int b[3];
		b[1]=0;
		b[2]=0;
		int b1=0,b2=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(b[a[j]]!=0&&a[j]==1){
					if(b[2]>b[1]) b[2]=0;
				}
				else if(b[a[j]]!=0&&a[j]==2){
					if(b[1]>b[2]) b[1]=0;
				}
				else{
					if(a[j]==1){
						b[a[j]]=b[2]+1;
					}
					else b[a[j]]=b[1]+1;
				}
			}
			b1+=(b[1]!=0);
			b2+=(b[2]!=0);
		}
		cout<<b1<<' '<<b2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	} 
	return 0;
}
//zong shi kun dun nan xing,yi dang di li fen jin
//纵使困顿难行，亦当砥砺奋进 
//ni shuo de dui,dan shi san guo sha shi yi kuan you you ka gong si yan fa de steam quan qiu cha ping bang di yi de quan fu gong xiang bao di ka pai you xi jian she ji you xi
//你说得对，但是三国杀是一款由游卡（狗卡）公司研发的steam全球差评榜第一的全服共享保底卡牌游戏兼射击游戏 
