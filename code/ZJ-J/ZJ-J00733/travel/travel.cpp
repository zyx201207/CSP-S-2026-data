#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;//100 pts
char ca[5],sa[5],cb[5],sb[5];
char out[5];
int paia,paib;
int posa,posb;
void solve(){
	scanf("%s%s%s%s",ca,sa,cb,sb);
	out[0]='0'+(strcmp(ca,cb)==0);
	if(out[0]=='0'){
		printf("0000");
		return;
	}
	paia=sa[0]*1000+sa[1];
	paib=sb[0]*1000+sb[1];
	out[1]='0'+(paia==paib);
	if(out[1]=='0'){
		printf("1000");
		return;
	}
	posa=sa[2]-'A';
	posb=sb[2]-'A';
	if((posa<3&&posb<3)||(posa>=3&&posb>=3)){
		out[2]='1';
		if((posa<3&&posb<3)){
			if(abs(posa-posb)==1){
				out[3]='1';
			}else{
				out[3]='0';
			}
		}else if((posa>=3&&posb>=3)){
			out[3]='1';
		}else{
			out[3]='0';
		}
	}else{
		out[2]='0';
		out[3]='0';
	}
	printf("%s",out);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
