#include<bits/stdc++.h>
using namespace std;
constexpr int N=10,sd[6]={0,0,0,1,1,1};
char c1[N],s1[N],c2[N],s2[N];
int cc1,cc2,ss1,ss2,id1,id2;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	scanf("%s",c1),scanf("%s",s1),scanf("%s",c2),scanf("%s",s2);
	cc1=(c1[0]-'0')*10+c1[1]-'0',cc2=(c2[0]-'0')*10+c2[1]-'0';
	putchar((cc1==cc2)+'0');
	ss1=(s1[0]-'0')*10+s1[1]-'0',ss2=(s2[0]-'0')*10+s2[1]-'0';
	putchar((cc1==cc2&&ss1==ss2)+'0');
	id1=s1[2]-'A',id2=s2[2]-'A';
	putchar((cc1==cc2&&ss1==ss2&&(sd[id1]==sd[id2]))+'0');
	putchar((cc1==cc2&&ss1==ss2&&(sd[id1]==sd[id2])&&(abs(id1-id2)==1))+'0');
	return 0;
}
//大家好,我有志于进入迷惑行为大赏。 
