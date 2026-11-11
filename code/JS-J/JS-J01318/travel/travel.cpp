#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int a1=0,a2=0,a3=0,a4=0,t1=int(s2[0]-'0')*10+int(s2[1]-'0'),t2=int(s4[0]-'0')*10+int(s4[1]-'0');
	if(s1==s3){
		a1=1;
		if(t1==t2){
			a2=1;
			if((s2[2]<='C' and s4[2]<='C')or(s2[2]>='D' and s4[2]>='D')){
				a3=1;
				if(abs(s2[2]-s4[2])==1 or (s2[2]=='D' and s4[2]=='F') or (s4[2]=='D' and s2[2]=='F')){
					a4=1;
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
