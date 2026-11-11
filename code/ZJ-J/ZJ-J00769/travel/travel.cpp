#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[2]=1;
			if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
				ans[3]=1;
				if(abs(int(b[2])-int(d[2]))==1||b[2]=='D'&&d[2]=='F'||d[2]=='D'&&b[2]=='F'){
					ans[4]=1;
				}
			}
		}
	}else{
		ans[1]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
