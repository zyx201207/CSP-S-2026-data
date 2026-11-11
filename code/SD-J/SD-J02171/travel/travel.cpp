#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[5],cnt2=0,cnt1=0,cnt3=0;
int a1,a2;
int main(){
	freopen("trvael.in","r",stdin);
	freopen("trvael.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		ans[0]=1;
		cnt1++;
	}else{
		ans[0]=0;
	}
	if(cnt1==1&&b[0]==d[0]&&b[1]==d[1]){
		ans[1]=1;
		cnt2++;
	}else{
		ans[1]=0;}
	if((cnt2==1&&b[2]-'A'>=0&&b[2]-'A'<=2&&d[2]-'A'>=0&&d[2]-'A'<=2)||(cnt2==1&&(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='f'))){
		ans[2]=1;
		cnt3++;
	}else{
		ans[2]=0;
	}
	a1=b[2]-'0';
	a2=d[2]-'0';
	if(cnt3==1&&(a1-a2==1||a1-a2==-1)){
		ans[3]=1;
	}else{
		ans[3]=0;
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
}
