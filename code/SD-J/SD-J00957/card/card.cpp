#include<bits/stdc++.h>
using namespace std;
const int M=3e5+1;
const int N=5e5+1;
int cnt,kind,card[N],point[M];
int outed[N],top=1,repi;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>cnt>>kind;
	for(int i=1;i<=cnt;++i){
		scanf("%d",&card[i]);
	}
	bool flag;
	for(int i=1;i<=cnt;++i){//Ä£Äâ¹ý³Ì 
		memset(outed,0,sizeof(outed));
		top=1;
		for(int j=i;j<=cnt;++j){
			flag=0;
			for(int k=1;k<=top;++k){
				if(outed[k]==card[j]){
					flag=1;
					repi=k;
					break;
				}
			}
			if(flag==0){
				outed[top]=card[j];
				++top;
			}
			else{
				for(int k=repi+1;k<=top;++k){
					outed[k]=0;
				}
				top=repi+1;
			}
		}
		for(int j=1;j<=top;++j){
			++point[outed[j]];
		}
	}
	for(int i=1;i<=kind;++i){
		printf("%d ",point[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

