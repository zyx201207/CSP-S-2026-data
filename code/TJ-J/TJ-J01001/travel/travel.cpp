#include<bits/stdc++.h>
using namespace std;
int s1,s2,ans[4];
char c1[11],c2[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&s1,c1,&s2,c2);
	if(s1==s2){
		ans[0]=1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			ans[1]=1;
			if(((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))||((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))){
				ans[2]=1;
				if(c1[2]==c2[2]+1||c1[2]==c2[2]-1||((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F')))
					ans[3]=1;
			}
		}
	}
	printf("%d%d%d%d",ans[0],ans[1],ans[2],ans[3]);
}
