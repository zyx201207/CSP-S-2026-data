#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a,b[30],s,h;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		h+=a;
		if(c=='a') b[1]++;
		else if(c=='b') b[2]++;
		else if(c=='c') b[3]++;
		else if(c=='d') b[4]++;
		else if(c=='e') b[5]++;
		else if(c=='f') b[6]++;
		else if(c=='g') b[7]++;
		else if(c=='h') b[8]++;
		else if(c=='i') b[9]++;
		else if(c=='g') b[10]++;
		else if(c=='k') b[11]++;
		else if(c=='l') b[12]++;
		else if(c=='m') b[13]++;
		else if(c=='n') b[14]++;
		else if(c=='o') b[15]++;
		else if(c=='p') b[16]++;
		else if(c=='q') b[17]++;
		else if(c=='r') b[18]++;
		else if(c=='s') b[19]++;
		else if(c=='t') b[20]++;
		else if(c=='u') b[21]++;
		else if(c=='v') b[22]++;
		else if(c=='w') b[23]++;
		else if(c=='x') b[24]++;
		else if(c=='y') b[25]++;
		else b[26]++;
	}
	for(int i=1;i<=26;i++) if(b[i]) s++;
	if(s==1) cout<<0;
	else cout<<h/2;
	return 0;
}ws
