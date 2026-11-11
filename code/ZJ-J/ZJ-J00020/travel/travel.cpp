#include<bits/stdc++.h>
using namespace std;
string a,s,a_,s_;
bool flag[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>a_>>s_;
	flag[1]=1;
	for(int i=0;i<2;i++){
		int num=a[i]-'0',num_=a_[i]-'0';
		if(num!=num_)flag[1]=0;
	}
	if(flag[1]){
		flag[2]=1;
		for(int i=0;i<2;i++){
			int num=s[i]-'0',num_=s_[i]-'0';
			if(num!=num_)flag[2]=0;
		}
		if(flag[2]){
			flag[3]=1,flag[4]=1;
			int c=s[2]-'A',c_=s_[2]-'A';
			if((c<=2&&c_<=2)||(c>2&&c_>2)){
				if(abs(c-c_)!=1){
					flag[4]=0;
				}
			}
			else{
				flag[3]=0,flag[4]=0;
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<flag[i];
	return 0;
}