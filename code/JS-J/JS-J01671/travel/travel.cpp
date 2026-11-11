#include<bits/stdc++.h>
using namespace std;

int n,a[4];
char s[4][9];

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",s[0],s[1],s[2],s[3]);
    
    if(s[0][0]==s[2][0]&&s[0][1]==s[2][1]){
		a[0]=1;
		if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
			a[1]=1;
			if((s[1][2]<'D')==(s[3][2]<'D')){
				a[2]=1;
				if((s[1][2]!='A'||s[3][2]!='C')&&(s[1][2]!='C'||s[3][2]!='A'))
					a[3]=1;
			}
		}
	}
    
    printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
}
