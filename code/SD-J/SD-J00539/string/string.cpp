#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ctrlcnt,charcnt1,charcntl,charcntr,remcharl,remcharr;
char charl,charr;
struct s{
	int len;
	char c;
}str[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].len>>str[i].c;
		charcnt1+=str[i].len;
	}
	charcntl=charcnt1/2;
	charcntr=charcntl;
	for(int i=1,j=n;;){
		if(charcntl>0&&charcntr>0){
			if(remcharl>charcntr){
				if(charl!=charr) ctrlcnt+=remcharr;
				remcharl-=remcharr;
				remcharr=0;
			}
			else if(charcntl<charcntr){
				if(charl!=charr) ctrlcnt+=remcharl;
				remcharr-=remcharl;
				remcharl=0;
			}
			else{
				if(charl!=charr) ctrlcnt+=remcharl;
				remcharl=0,remcharr=0;
			}
		}
		else{
			if(charl!=charr) ctrlcnt+=remcharl;
			break;
		}
		if(remcharl==0){
			if(charcntl-str[i].len>0){
				charcntl-=str[i].len;
				charl=str[i].c;
				remcharl=str[i].len;
				i++;
				continue;
			}else{
				charl=str[i].c;
				remcharl=charcntl;
				charcntl=0;
			}
		}
		if(remcharr==0){
			if(charcntr-str[j].len>0){
				charcntr-=str[j].len;
				charr=str[j].c;
				remcharr=str[j].len;
				j--;
			}else{
				charr=str[j].c;
				remcharr=charcntr;
				charcntr=0;
			}
		}
	}
	cout<<ctrlcnt;
	return 0;
}
