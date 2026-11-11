#include<bits/stdc++.h>
using namespace std;
string sA,sB,sC,sD;
bool solveA(){//判断第一个问题
	if(sA==sC)return 1;
	else return 0;
}
bool solveB(){//以此类推
	if(sB[0]==sD[0]&&sB[1]==sD[1])return 1;
	else return 0;
}
bool solveC(){
	bool checkA[7]={1,1,1,0,0,0};
    if(checkA[sB[2]-'A']==checkA[sD[2]-'A'])return 1;
    else return 0;
}
bool solveD(){
	char chck[10]={'A','B','C','#','D','F'};
	int lsa;
	for(int i=0;i<5;i++)if(sB[2]==chck[i])lsa=i;
    char LB=(chck[lsa]=='A'?'*':chck[lsa-1]);
    char RB=(chck[lsa]=='F'?'*':chck[lsa+1]);
    if(sD[2]==LB||sD[2]==RB)return 1;
    else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sA>>sB>>sC>>sD;
	bool AD=solveA();
	bool BD=solveB();
 	bool CD=solveC();
	bool DD=solveD();
	cout<<AD<<(AD&BD)<<(AD&BD&CD)<<(AD&BD&DD);
	return 0;
}
