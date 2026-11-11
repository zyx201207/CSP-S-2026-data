#include <bits/stdc++.h>
using namespace std;
bool ans[4]={0,0,0,0};
string r,x;
string num_r,num_x;
string jq(string a){
	string res="";
	for (int i=0;i<2;i++){
		res+=a[i];
	}
	return res;
}
bool istc(char a,char b){
	return (((a<='C'&&a>='A')==(b<='C'&&b>='A'))&&(jq(r)==jq(x))&&(num_r==num_x));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>num_r>>r>>num_x>>x;
	ans[0]=(num_r==num_x);
	ans[1]=((jq(r)==jq(x))&&(ans[0]==1));
	ans[2]=istc(r[2],x[2]);
	ans[3]=(((int(r[2])-int(x[2]))==1||(int(r[2])-int(x[2]))==-1)&&(ans[2]==1));
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
