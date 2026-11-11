#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string c1,s1,c2,s2;
bool f;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	c1=' '+c1,s1=' '+s1,c2=' '+c2,s2=' '+s2;
	if(c1==c2) a[1]=1;
	else a[1]=0;
	bool f=0;
	for(int i=1;i<=2;i++){
		if(s1[i]!=s2[i]){
			f=1;
			break;
		}
	}
	if(f==0&&a[1]==1) a[2]=1;
	else a[2]=0;
	bool f1=0,f2=0;
	if(a[2]==1){
		if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))){
			a[3]=1;
			f1=1;
		}else{
			if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
				a[3]=1;
				f2=1;
			}else{
				a[3]=0;
			}
		}
	}
	else a[3]=0;
	if(a[3]==1){
		if(f1==1&&abs((s1[3]-'0')-(s2[3]-'0'))==1){
			a[4]=1;
		}else if(f2==1&&abs((s1[3]-'0')-(s2[3]-'0'))==2){
			a[4]=1;
		}else{
			a[4]=0;
		}
	}
	else a[4]=0;
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 
